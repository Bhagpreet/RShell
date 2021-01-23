#include "gtest/gtest.h"
#include "command.cpp"
#include "and.cpp"
#include "or.cpp"
#include "semicolon.cpp"
#include "shell.cpp"
#include "command.h"
#include "and.h"
#include "or.h"
#include "semicolon.h"
#include "shell.h"

TEST(command, object) {
    Command* command1 = new Command("ls -a");
    Command* command2 = new Command("fails");
    Command* command3 = new Command("echo testing multiple words echoed");

    EXPECT_EQ("ls -a", command1->val);
    EXPECT_EQ("fails", command2->val);
    EXPECT_EQ("echo testing multiple words echoed", command3->val);

    testing::internal::CaptureStdout();
    command1->execute();
    command2->execute();
    command3->execute();
	string output = testing::internal::GetCapturedStdout();
    // the command that fails outputs that the Child process was destroyed and the command failed in ./test
    EXPECT_EQ(".\n..\nand.cpp\nand.h\na.out\nAssignment1.pdf\nbase.h\nbin\nCMakeCache.txt\nCMakeFiles\ncmake_install.cmake\nCMakeLists.txt\ncommand.cpp\ncommand.h\n.git\n.gitmodules\ngoogletest\nlib\nmain.cpp\nMakefile\nor.cpp\nor.h\nREADME.md\nsemicolon.cpp\nsemicolon.h\nshell.cpp\nshell.h\ntest\ntest.cpp\n\ntesting multiple words echoed\n\n", output);
}

TEST(and, object) {
    And* and1 = new And(new Command("mkdir testFolder"));
    And* and2 = new And(new Command("rm -rf testFolder"));
    And* and3 = new And(new Command("echo testing 123"));

    testing::internal::CaptureStdout();
    and1->execute();
    and2->execute();
    and3->execute();
	string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("\n\ntesting 123\n\n", output);
}

TEST(or, object) {
    Or* or1 = new Or(new Command("echo hello world"));
    Or* or2 = new Or(new Command("fails"));
    Or* or3 = new Or(new Command("echo peter piper picked a pile of peppers"));

    testing::internal::CaptureStdout();
    or1->execute();
    or2->execute();
    or3->execute();
	string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("hello world\n\npeter piper picked a pile of peppers\n\n", output);
}

TEST(semicolon, object) {
    Semicolon* semicolon1 = new Semicolon(new Command("touch earth.h"));
    Semicolon* semicolon2 = new Semicolon(new Command("rm -rf earth.h"));
    Semicolon* semicolon3 = new Semicolon(new Command("echo testing works"));

    testing::internal::CaptureStdout();
    semicolon1->execute();
    semicolon2->execute();
    semicolon3->execute();
	string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("\n\ntesting works\n\n", output);    
}

TEST(shell, object) {
    Shell* shell1 = new Shell("ls -a; echo hello && mkdir test && rm -rf test; exit # yes sir");
    Shell* shell2 = new Shell("echo run && echo run && exit || cout # echo dont run");
    Shell* shell3 = new Shell("exit");

    testing::internal::CaptureStdout();
    shell1->execute();
    shell2->execute();
    shell3->execute();
	string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(".\n..\nand.cpp\nand.h\na.out\nAssignment1.pdf\nbase.h\nbin\nCMakeCache.txt\nCMakeFiles\ncmake_install.cmake\nCMakeLists.txt\ncommand.cpp\ncommand.h\n.git\n.gitmodules\ngoogletest\nlib\nmain.cpp\nMakefile\nor.cpp\nor.h\nREADME.md\nsemicolon.cpp\nsemicolon.h\nshell.cpp\nshell.h\ntest\ntest.cpp\n\nhello\n\nrun\n\nrun\n\n", output);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}