# Target 10.11+
CFLAGS = -mmacosx-version-min=10.11 -arch x86_64 -arch arm64 
export CFLAGS

TARGET ?= $(CURDIR)/target
BUILDPREFIX ?= $(CURDIR)/tmp
CCIDVER ?= 1.5.5
#$(shell cd CCID-1.5.5 )

PKG_CONFIG_PATH = $(BUILDPREFIX)/lib/pkgconfig
export PKG_CONFIG_PATH

# SIGNER ?= FEITIAN Technologies Co.,Ltd. (S47T4UESP3)
SIGNER ?=FEITIAN Technologies Co.,Ltd. (S47T4UESP3)
ifneq ($(strip $(SIGNER)),)
  PKGSIGN = --sign "Developer ID Installer: $(SIGNER)"
endif

.PHONY: default clean
.NOTPARALLEL default: clean dmg srcdist

pkg: ccid-installer.pkg
dmg: ccid-installer.dmg

clean:
	rm -rf target tmp *.pkg *.dmg *.zip

LIBUSB = $(BUILDPREFIX)/lib/libusb-1.0.a
BUNDLE = $(TARGET)/usr/local/libexec/SmartCardServices/drivers/ifd-ccid.bundle

$(LIBUSB):
	(cd libusb \
	&& ./autogen.sh \
	&& ./configure --prefix=$(BUILDPREFIX) --disable-dependency-tracking --enable-static --disable-shared --host=aarch64-apple-darwin --host=x86_64-apple-darwin  \
	&& $(MAKE) \
	&& $(MAKE) install \
	)


$(BUNDLE): $(LIBUSB)
	(cd CCID-1.5.5 \
	&& ./bootstrap \
	&& ./MacOSX/configure \
	&& $(MAKE) \
	&& $(MAKE) install DESTDIR=$(TARGET) \
	)

srcdist:
	$(MAKE) -C CCID-1.5.5 dist-gzip

ifd-ccid.pkg: $(BUNDLE)
	codesign --timestamp --options=runtime -f -s "Developer ID Application: $(SIGNER)" $(LIBUSB)
	codesign --timestamp --options=runtime -f -s "Developer ID Application: $(SIGNER)" $(BUNDLE)
	pkgbuild --root $(TARGET) --scripts scripts --identifier org.openkms.mac.ccid --version $(CCIDVER) --install-location / --ownership recommended $@
	mv ifd-ccid.pkg ifd-ccid_new.pkg
	productsign --timestamp --options=runtime -f  -s "Developer ID Installer: FEITIAN Technologies Co.,Ltd. (S47T4UESP3)" ifd-ccid_new.pkg ifd-ccid.pkg
	xcrun notarytool submit ifd-ccid_new.pkg --keychain-profile "FT_ENTERSAFE"

ccid-installer.pkg: ifd-ccid.pkg
	productbuild --distribution Distribution.xml --package-path . --resources resources $(PKGSIGN) $@
	mv ccid-installer.pkg ccid-installer_new.pkg
	productsign --timestamp --options=runtime -f  -s "Developer ID Installer: FEITIAN Technologies Co.,Ltd. (S47T4UESP3)" ccid-installer_new.pkg ccid-installer.pkg

uninstall.pkg: uninstaller-scripts/postinstall
	pkgbuild --nopayload --identifier org.openkms.mac.ccid.uninstall --scripts uninstaller-scripts $(PKGSIGN) $@
	mv uninstall.pkg uninstall_new.pkg
	productsign --timestamp --options=runtime -f  -s "Developer ID Installer: FEITIAN Technologies Co.,Ltd. (S47T4UESP3)" uninstall_new.pkg uninstall.pkg

ccid-installer.dmg: ccid-installer.pkg uninstall.pkg
	hdiutil create -ov -srcfolder uninstall.pkg -srcfolder ccid-installer.pkg -volname "CCID installer ($(CCIDVER))" $@
	zip -r ccid-installer.zip ccid-installer.dmg
#	productsign --timestamp -s "Developer ID Installer: FEITIAN Technologies Co.,Ltd. (S47T4UESP3)" ccid-installer_new.dmg ccid-installer.dmg
	xcrun notarytool submit ccid-installer.zip --keychain-profile "FT_ENTERSAFE"

#Verify: xcrun notarytool info "id" --keychain-profile "FT_ENTERSAFE"
