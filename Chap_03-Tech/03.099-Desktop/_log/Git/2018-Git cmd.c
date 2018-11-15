
//================================
1016-Git cmd:
{
all shell interface, enter 3 times.

01. start:
	git help cmd...
	git cmd -h
	git cmd --help

	git clone ... git@aaes.githost.io:AAESSwingDoor/SwingDoorPlatform.git 
				not //https://
	git init ...
	git submodule
	
	git config --list, --global

02. current dir:
	add .
	mv /rm
	reset

03. history:
	bisect  binary search commit
	grep    pattern match, ge lai po.
	log === -5, --graph===,
	show 
	status -s ===

04. grow work.
	branch -r -d -Delete
	checkout === (recover ***.file)
	commit -am ''
	diff     ===
	merge    ===
	rebase
	tag
	
05. work flow.
	git rest xxx => git pull => git merge --no-ff -m'xxx',
	=> git rm /add =>commit -am'' => git push.
	git log -5, git status...

	fetch
	pull
	push.

06. diff /merger tool.
	git config diff.tool 	  //config check xxx...
	git difftool --tool-help  //difftool help.
	git config --global diff.tool meld. //global config.
07. skill:
	git config --global alias.st status
	git config --global alias.name "config --global alias" //////error.

	'usr/.gitconig'
	cygwin cmd dos2unix file.//===//notepad++.

[alias]
    st = status
    ci = commit
    co = checkout
    br = branch
    unstage = reset HEAD -- 
    last = log -1 HEAD	//git config --global alias.last 'log -1 HEAD'

08. submodule:
	git submodule update --init --recursive

09. git reflog. after reset.!!!.

10. .ignore file
	----------------------------------------------
	git ignose file.
	{
	.gitignore

	_output/
	_output_icTest/
	*.pyc
	*.bak
	cscope.*
	tags
	.pydevproject
	_openocd.log
	.settings/language.settings.xml
	*/_output/
	.d/
	}

29. ssh key.
=============================================================
+---[RSA 4096]----+
|...oo oo+        |
|.+ ..=.*         |
|E.+ +oB .        |
|.o o.* * + .     |
|+   + * S *      |
|+.   = + O       |
|=     +          |
|+.     .         |
|.=.              |
+----[SHA256]-----+

ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAACAQDrIeojWTXfT8R4glTNrncvpoSFPn4Db7vhLQA4BSGBB9hHqo86WFA2+UpvcV9qgPyY4a8PXmAToktYUSDH+y8ERMbqerSD+PGnE9jR1DkmiIkm1IzX/Qkcp/FrHXk5TacG/PDVWDPAcRNaJdqidNLu+cn3mFbIRBBfDeZTYwZcY5X1FTmjgn4xOfCEggkBVUTgtUg+Xgcm5ncaiEoXTiDnmhq1mEPSPK3rBUdmuymJisYIjylpzWSXaBTpUjBbD5x6id10+bedS5qIAk9A1p9yTVQsR0MMdpf5z9OBi673UQk7ckIysxwk31PPejhGwVPRnAJweM9jhvWwF5Lu/LQK/e0ial0mNVnSmslVNe0sv8R23ccD+e7ZkPByA133GNhGguywlvD9MfdFBJOirBM9eoo8DN6xfp9J1GhD1XMgSbReJoEfoF0s1ryF7scruVblrfmIsS45FoMcQCjQYxlI01p20BLyYIrYgFc3nupKcA0tw/mFSwg+6sRr5aL/32BxFtz+PoDkTz2RP+QTvWjlg5LllMiPW2lKRfUV4gAwX+M0bk6GHMPEtem05DC9ML06PAZ6E4OGjV03bsYBhoFa94F+aqf0t+t44AkyXYd+K6zr7MeG6ZUvvWniYVYF/yoz8+Z2zPTcfKRw5G6tNk7M/4fvczi1u1p1mzjFHuYjPw== Jerry.Hua@assaabloy.com

}
//1016.