# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.atbash-cipher.Debug:
/Users/viraltaco/code/Exercism/cpp/atbash-cipher/build/Debug/atbash-cipher:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/atbash-cipher/build/Debug/atbash-cipher


PostBuild.atbash-cipher.Release:
/Users/viraltaco/code/Exercism/cpp/atbash-cipher/build/Release/atbash-cipher:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/atbash-cipher/build/Release/atbash-cipher


PostBuild.atbash-cipher.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/atbash-cipher/build/MinSizeRel/atbash-cipher:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/atbash-cipher/build/MinSizeRel/atbash-cipher


PostBuild.atbash-cipher.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/atbash-cipher/build/RelWithDebInfo/atbash-cipher:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/atbash-cipher/build/RelWithDebInfo/atbash-cipher




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libboost_date_time-mt.a:
/usr/local/lib/libboost_regex-mt.a:
/usr/local/lib/libboost_unit_test_framework-mt.a:
