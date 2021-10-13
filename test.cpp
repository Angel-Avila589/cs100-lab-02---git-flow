#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
	EXPECT_EQ("hello world", echo(3, test_val));
}

TEST(EchoTest, EmptyString) {
	char* test_val[1]; test_val[0] = "./c-echo";
	EXPECT_EQ("", echo(1, test_val));
}

TEST(EchoTest, SameString) {
	char* test_val1[2]; test_val1[0] = "./c-echo"; test_val1[1] = "Are we the same?";
	char* test_val2[2]; test_val2[0] = "./c-echo"; test_val2[1] = "Are we the same?";
	EXPECT_EQ(echo(2, test_val1), echo(2, test_val2));  

}

TEST(EchoTest, CombineStrings) {
	char* test_val1[2]; test_val1[0] = "./c-echo"; test_val1[1] = "Hello";
	char* test_val2[2]; test_val2[0] = "./c-echo"; test_val2[1] = "World";
	EXPECT_EQ("HelloWorld", echo(2, test_val1) + echo(2, test_val2) );
}

TEST(EchoTest, CaseSensitiveString) {
	char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "TEST";
	EXPECT_FALSE("test" ==  echo(2, test_val));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
