# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.meetup.Debug:
/Users/viraltaco/code/code/Exercism/cpp/meetup/build/Debug/meetup:\
	/usr/local/lib/libboost_date_time.a
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/meetup/build/Debug/meetup


PostBuild.meetup.Release:
/Users/viraltaco/code/code/Exercism/cpp/meetup/build/Release/meetup:\
	/usr/local/lib/libboost_date_time.a
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/meetup/build/Release/meetup


PostBuild.meetup.MinSizeRel:
/Users/viraltaco/code/code/Exercism/cpp/meetup/build/MinSizeRel/meetup:\
	/usr/local/lib/libboost_date_time.a
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/meetup/build/MinSizeRel/meetup


PostBuild.meetup.RelWithDebInfo:
/Users/viraltaco/code/code/Exercism/cpp/meetup/build/RelWithDebInfo/meetup:\
	/usr/local/lib/libboost_date_time.a
	/bin/rm -f /Users/viraltaco/code/code/Exercism/cpp/meetup/build/RelWithDebInfo/meetup




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libboost_date_time.a:
