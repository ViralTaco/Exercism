# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.scrabble-score.Debug:
/Users/viraltaco/code/Exercism/cpp/scrabble-score/build/Debug/scrabble-score:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/scrabble-score/build/Debug/scrabble-score


PostBuild.scrabble-score.Release:
/Users/viraltaco/code/Exercism/cpp/scrabble-score/build/Release/scrabble-score:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/scrabble-score/build/Release/scrabble-score


PostBuild.scrabble-score.MinSizeRel:
/Users/viraltaco/code/Exercism/cpp/scrabble-score/build/MinSizeRel/scrabble-score:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/scrabble-score/build/MinSizeRel/scrabble-score


PostBuild.scrabble-score.RelWithDebInfo:
/Users/viraltaco/code/Exercism/cpp/scrabble-score/build/RelWithDebInfo/scrabble-score:\
	/usr/local/lib/libboost_unit_test_framework-mt.a\
	/usr/local/lib/libboost_date_time-mt.a\
	/usr/local/lib/libboost_regex-mt.a
	/bin/rm -f /Users/viraltaco/code/Exercism/cpp/scrabble-score/build/RelWithDebInfo/scrabble-score




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libboost_date_time-mt.a:
/usr/local/lib/libboost_regex-mt.a:
/usr/local/lib/libboost_unit_test_framework-mt.a:
