#!/bin/sh
# author_video_ts.sh - build a one-title NTSC DVD folder (dvd/disc/VIDEO_TS, with an empty AUDIO_TS next to it) from streams/test_ntsc_dvd.vob with dvdauthor (issue #93: DVD Player only opens a disc folder, not a bare .mpg).
# DVDAUTHOR=/path/to/dvdauthor sh author_video_ts.sh   (default: dvdauthor from PATH). dvdauthor was built from https://github.com/ldo/dvdauthor (0.7.2+) with
# `./configure --disable-dvdunauthor --without-imagemagick --without-graphicsmagick && make -C src` inside a throwaway conda-forge environment (compilers, autotools, libxml2-devel, libpng, freetype,
# fribidi, zlib, gettext); the manual pages need docbook tools and are skipped.
cd "`dirname "$0"`" || exit 1
DA=${DVDAUTHOR:-dvdauthor}; rm -rf dvd; mkdir -p dvd
cat > dvd/dvd.xml <<XML
<dvdauthor dest="dvd/disc">
  <vmgm />
  <titleset>
    <titles>
      <video format="ntsc" aspect="4:3" />
      <pgc><vob file="streams/test_ntsc_dvd.vob" chapters="0" /></pgc>
    </titles>
  </titleset>
</dvdauthor>
XML
VIDEO_FORMAT=NTSC $DA -x dvd/dvd.xml 2>&1 | tail -15
ls -l dvd/disc/VIDEO_TS
