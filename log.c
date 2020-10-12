Last login: Sun Oct 11 11:42:38 on console
zintan@Omars-MacBook-Pro ~ % ssh knuth
Password: 
	
	knuth: HMC Computer Science Department         nServ A413.v3
	Gentoo Linux/amd64
	        64 cores (4x AMD Opteron 6276) with 512GB RAM

	>>>>>>>>>>>>>>>>>>> AWESOME USERS ONLY! <<<<<<<<<<<<<<<<<<<<

	Upon encountering bizarre behavior, open a ticket:
	   https://request.cs.hmc.edu/
	
	System policy is detailed at the following web page:
	   https://www.cs.hmc.edu/wiki/QREF/Policy
	Users are responsible for reading and following all system 
	policies. Use of this system implies consent to follow all 
	system policies.

	Compliance will result in friendship with this majestic bear:
	   http://bit.ly/Q9vL9s

	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Last login: Mon Oct 12 12:47:23 2020 from 66.116.81.212
perl: warning: Setting locale failed.
perl: warning: Please check that your locale settings:
	LANGUAGE = (unset),
	LC_ALL = (unset),
	LC_CTYPE = "UTF-8",
	LANG = (unset)
    are supported and installed on your system.
perl: warning: Falling back to the standard locale ("C").
perl: warning: Setting locale failed.
perl: warning: Please check that your locale settings:
	LANGUAGE = (unset),
	LC_ALL = (unset),
	LC_CTYPE = "UTF-8",
	LC_COLLATE = "POSIX",
	LANG = "en_US.UTF-8"
    are supported and installed on your system.
perl: warning: Falling back to a fallback locale ("en_US.UTF-8").
perl: warning: Setting locale failed.
perl: warning: Please check that your locale settings:
	LANGUAGE = (unset),
	LC_ALL = (unset),
	LC_CTYPE = "UTF-8",
	LC_COLLATE = "POSIX",
	LANG = "en_US.UTF-8"
    are supported and installed on your system.
perl: warning: Falling back to a fallback locale ("en_US.UTF-8").
atrujillo dodds is mhwong mlavioll omatthews oneill rhodes zdodds zmwinilayuori 

12:48 [zmwinilayuori@knuth:~]
1 % cd cs134/xv6-public 
12:50 [zmwinilayuori@knuth:~/cs134/xv6-public]
2 % git status
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	modified:   Makefile

Untracked files:
  (use "git add <file>..." to include in what will be committed)
	#.cvsignore#
	#barrier.c#
	a.out
	barrier.c
	uthread.c
	uthread_switch.S

no changes added to commit (use "git add" and/or "git commit -a")
12:50 [zmwinilayuori@knuth:~/cs134/xv6-public]
3 % emacs Makefile 
12:50 [zmwinilayuori@knuth:~/cs134/xv6-public]
4 % git diff Makefile 
12:51 [zmwinilayuori@knuth:~/cs134/xv6-public]
5 % emacs log.c

File Edit Options Buffers Tools C Help             

// Copy committed blocks from log to their home lo\
cation                                             
static void
install_trans(int recovery)
{
  int tail;
  if (recovery) {
    for (tail = 0; tail < log.lh.n; tail++) {
      struct buf *lbuf = bread(log.dev, log.start+\
tail+1); // read log block                         
    struct buf *dbuf = bread(log.dev, log.lh.block\
[tail]); // read dst                               
    memmove(dbuf->data, lbuf->data, BSIZE);
    bwrite(dbuf);  // write dst to disk            
    brelse(lbuf);
    brelse(dbuf);
    }
  } else {
    for (tail = 0; tail < log.lh.n; tail++) {
    struct buf *dbuf = bread(log.dev, log.lh.block\
[tail]); // read dst                               
    bwrite(dbuf);  // write dst to disk            
    brelse(dbuf);
    }
  }
}

// Read the log header from disk into the in-memor\
y log header                                       
static void
read_head(void)
{
  struct buf *buf = bread(log.dev, log.start);
  struct logheader *lh = (struct logheader *) (buf\
->data);
  int i;
  log.lh.n = lh->n;
  for (i = 0; i < log.lh.n; i++) {
    log.lh.block[i] = lh->block[i];
  }
  brelse(buf);
-UU-:----F1  log.c          28% L79   Git:master  (
Quit
