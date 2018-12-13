

//======================addr2line======================
01. /c/mbs/programs/bin/addr2line.exe -e products-quasarMotor.elf 0x803103f
$ /c/mbs/programs/bin/addr2line -e products-quasarMotor.elf 0x801d03f
C:\mbs\SwingDoorPlatform/components/application/aaesGeneric/messageRouter/src/messageRouter.cpp:236

void MessageRouterImp::vTransmitToOneNode ( MbsMsg* const pMessageCopy, const uint8_t ui8RxIndex )
mbsAssert( MBS_STATUS_OK == mbsMsgSend( NULL, address, pMessageCopy, MBS_MSG_TIMEOUT_NOW ) );


02. ## Assert failed at LR 0x801D03F, task commApp
 CAN send message to MIAN, MAIN need to register message, but NOT.
 
03. vTaskDelayUntil( &xLastWakeTime, 100 );
	static void commApp( void* pvParameters )
	
04. messageRoutingTable.cpp ///* ui8Subscribers     */ { static_cast<uint8_t>( MAIN ), 255U }  
						      /* ui8Subscribers     */ {255U, 255U }
C:\mbs\SwingDoorPlatform\modules\messageRouter\motorBoard\mbs_st_m64_core_v10\config\src\messageRoutingTable.cpp



//======================add path======================
#echo $SHELL
	/bin/bash
#echo $HONME
	/c/Users/jerhua
#vim $HOME/.bash_profile
	GCC_PATH=/C/mbs/mbsToolchains/gcc-arm-none-eabi-4_9-2015q3/bin
	MBS_BIN=/C/mbs/programs/bin
	export PATH=$PATH:$GCC_PATH:$MBS_BIN
	:wq
#source $HOME/.bash_profile
#echo $PATH
    .../gcc-arm-none-eabi-4_9-2015q3/bin

cygwin提供了一个.bat文件	
/cygwin/etc/skel里面找，里面只有3个文件.bash_profile, .bashrc 和 .inputrc。
copy .bash_profile to '/c/Users/jerhua' ($HONME)
	
//======================add path======================
/***CMD LIST: ls $MBS_BIN
$ ls $MBS_BIN
'[.exe'*                 cyggdbm-4.dll*               /find.exe*                       link.exe*           preconv.exe*        tailf.exe*
 2to3*                   cyggmp-10.dll*               flock.exe*                       lkbib.exe*          pre-grohtml.exe*    tar.exe*
 addftinfo.exe*          cyggomp-1.dll*               fmt.exe*                         ln.exe*             printenv.exe*       tbl.exe*
 /addr2line.exe*          cyghistory7.dll*             fold.exe*                        locale.exe*       /printf.exe*         tee.exe*
 apropos@                cygiconv-2.dll*              gawk.exe*                        locate.exe*         ps.exe*             test.exe*
 /ar.exe*                 cygintl-8.dll*               gawk-4.2.1.exe*                  logger.exe*        ptx.exe*            tfmtodit.exe*
 arch.exe*               cygisl-15.dll*               gcc.exe*                         login.exe*          pwd.exe*            tic.exe*
 /as.exe*                 cyglsa.dll*                  gcc-ar.exe*                      logname.exe*       pydoc@              timeout.exe*
 ash.exe*                cyglsa64.dll*                gcc-nm.exe*                      look.exe*           pydoc2@             toe.exe*
 awk@                    cyglsa-config*               gcc-ranlib.exe*                  lookbib.exe*        pydoc2.7*           touch.exe*
 b2sum.exe*              cyglzma-5.dll*               /gcov.exe*                      /ls.exe*             pygettext.py*       tput.exe*
 base32.exe*             cygmagic-1.dll*              gcov-dump.exe*                   lzcat@              python@             tr.exe*
 base64.exe*             cygman-2-7-6-1.dll*          gcovr*                           lzcmp@              python2@            troff.exe*
 basename.exe*           cygmandb-2-7-6-1.dll*        gcov-tool.exe*                   lzdiff@             python2.7.exe*      true.exe*
 bash.exe*               cygmenuw-10.dll*             gdiffmk*                         lzegrep@            ranlib.exe*         truncate.exe*
 bashbug*                cygmpc-3.dll*                gencat.exe*                      lzfgrep@            readelf.exe*        trust.exe*
 bunzip2.exe*            cygmpfr-4.dll*               getconf.exe*                     lzgrep@             readlink.exe*       tset.exe*
 bzcat.exe*              cygmpfr-6.dll*               getent.exe*                      lzless@             readshortcut.exe*   tsort.exe*
 bzcmp@                  cygncursesw-10.dll*          getfacl.exe*                     lzma@               realpath.exe*       tty.exe*
 bzdiff*                 cygp11-kit-0.dll*            getopt.exe*                      lzmadec.exe*        rebase.exe*         tzselect*
 bzegrep@                cygpanelw-10.dll*            gkill.exe*                       lzmainfo.exe*       rebaseall*          tzset.exe*
 bzfgrep@                cygpath.exe*                 gprof.exe*                       lzmore@             rebaselst*          ul.exe*
 bzgrep*                 cygpcre-1.dll*               grap2graph*                     /man.exe*            rebase-trigger*    /umount.exe*
 bzip2.exe*              cygpipeline-1.dll*           grep.exe*                        mandb.exe*          refer.exe*          uname.exe*
 bzip2recover.exe*       cygpopt-0.dll*               grn.exe*                         manpath.exe*        regtool.exe*        unexpand.exe*
 bzless@                 cygquadmath-0.dll*           grodvi.exe*                      mcookie.exe*        rename.exe*         uniq.exe*
 bzmore*                 cygreadline7.dll*            groff.exe*                       md5sum.exe*         renice.exe*         unlink.exe*
 c++filt.exe*            cygserver-config*            grolbp.exe*                      minidumper.exe*     reset@              unlzma@
 c89*                    cygsigsegv-2.dll*            grolj4.exe*                      mintheme*           rev.exe*            unxz@
 c99*                    cygsmartcols-1.dll*          grops.exe*                       mintty.exe*        /rm.exe*             update-ca-trust*
 cal.exe*                cygsqlite3-0.dll*            grotty.exe*                      mkdir.exe*         /rmdir.exe*          updatedb*
 ca-legacy*              cygssl-1.0.0.dll*            groups.exe*                      mkfifo.exe*         run.exe*            users.exe*
 captoinfo@              cygstart.exe*                gunzip*                          mkgroup.exe*        runcon.exe*         uuidgen.exe*
 cat.exe*                cygstdc++-6.dll*             gzexe*                           mknod.exe*          rvi@                vdir.exe*
 catman.exe*             cygtasn1-6.dll*              /gzip.exe*                       mkpasswd.exe*       rview@             /vi.exe*
 cc@                     cygticw-10.dll*              head.exe*                        mkshortcut.exe*     script.exe*         view@
 chcon.exe*              cyguuid-1.dll*               hexdump.exe*                     mktemp.exe*         scriptreplay.exe*   wc.exe*
 chgrp.exe*              cygwin1.dll*                 hostid.exe*                      more.exe*           sdiff.exe*         /whatis.exe*
 chmod.exe*              cygwin-console-helper.exe*   /hostname.exe*                   mount.exe*          sed.exe*           /whereis.exe*
 chown.exe*              cygz.dll*                    hpftodit.exe*                    msgfmt.py*          seq.exe*           /which.exe*
 chroot.exe*             dash.exe*                    i686-pc-cygwin-gcc.exe*          mv.exe*             setfacl.exe*       /who.exe*
 cksum.exe*              /date.exe*                   i686-pc-cygwin-gcc-6.4.0.exe*    namei.exe*          setmetamode.exe*   /whoami.exe*
 clear.exe*              dd.exe*                      i686-pc-cygwin-gcc-ar.exe*       neqn*               setsid.exe*         windmc.exe*
 cmp.exe*                /df.exe*                     i686-pc-cygwin-gcc-nm.exe*       nice.exe*          /sh.exe*             windres.exe*
 col.exe*                /diff.exe*                   i686-pc-cygwin-gcc-ranlib.exe*   nl.exe*             sha1sum.exe*        xargs.exe*
 colcrt.exe*             diff3.exe*                   iconv.exe*                       nm.exe*             sha224sum.exe*      xz.exe*
 colrm.exe*              /dir.exe*                    id.exe*                          nohup.exe*          sha256sum.exe*      xzcat@
 column.exe*             dircolors.exe*               indxbib.exe*                     nproc.exe*          sha384sum.exe*      xzcmp@
 comm.exe*               dirname.exe*                 info.exe*                        nroff*              sha512sum.exe*      xzdec.exe*
 /cp.exe*                 dlltool.exe*                 infocmp.exe*                    numfmt.exe*         shred.exe*          xzdiff*
 cpp.exe*                dllwrap.exe*                 infotocap@                      /objcopy.exe*        shuf.exe*           xzegrep@
 csplit.exe*             dnsdomainname@               /install.exe*                   /objdump.exe*        size.exe*           xzfgrep@
 cut.exe*                domainname@                  install-info.exe*                od.exe*            /sleep.exe*          xzgrep*
 cygargp-0.dll*          /du.exe*                      ipcmk.exe*                      openssl.exe*        smtpd.py*           xzless*
 cygatomic-1.dll*        dumper.exe*                  ipcrm.exe*                       p11-kit.exe*        soelim.exe*         xzmore*
 cygattr-1.dll*          /echo.exe*                    ipcs.exe*                       passwd.exe*        /sort.exe*           yes.exe*
 cygblkid-1.dll*         editrights.exe*              isosize.exe*                     paste.exe*          split.exe*          zcat*
 cygbz2-1.dll*           egrep*                       join.exe*                        pathchk.exe*        ssp.exe*            zcmp*
 cygcheck.exe*           elfedit.exe*                 /kill.exe*                       pdfroff*            stat.exe*           zdiff*
 cygcrypt-0.dll*         env.exe*                     lastlog.exe*                     peflags.exe*        stdbuf.exe*         zegrep*
 cygcrypto-1.0.0.dll*    eqn.exe*                     ld.bfd.exe*                      peflagsall*         strace.exe*         zfgrep*
 cygdb_cxx-5.3.dll*      eqn2graph*                   /ld.exe*                         pfbtops.exe*        strings.exe*        zforce*
 cygdb_sql-5.3.dll*      ex@                          ldd.exe*                         pg.exe*             strip.exe*          zgrep*
 cygdb-5.3.dll*          expand.exe*                  ldh.exe*                         pic.exe*            stty.exe*           zless*
 cygexpat-1.dll*         expr.exe*                    less.exe*                        pic2graph*          sum.exe*            zmore*
 cygffi-6.dll*           factor.exe*                  lessecho.exe*                    pinky.exe*          sync.exe*           znew*
 cygformw-10.dll*        false.exe*                   lesskey.exe*                     pldd.exe*           tabs.exe*
 cyggcc_s-1.dll*         fgrep*                       lexgrog.exe*                     post-grohtml.exe*   tac.exe*
 cyggdbm_compat-4.dll*   file.exe*                    libpython2.7.dll*                pr.exe*             tail.exe*

***/
