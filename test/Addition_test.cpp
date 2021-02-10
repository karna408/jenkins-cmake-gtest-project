// SOURCE CODE FROM https://wiki.openssl.org/index.php/EVP_Symmetric_Encryption_and_Decryption

#include <gtest/gtest.h>
#include "Addition.h"

TEST(TestingAddition, success) {
	  ASSERT_TRUE(true);
}

TEST(TestingAddition, CTOR) {
    zf::sample::Addition myAddition = zf::sample::Addition();
	  ASSERT_TRUE(true);
}

TEST(TestingAddition, add) {
    zf::sample::Addition myAddition = zf::sample::Addition();
		ASSERT_EQ(myAddition.add(1,1), 2);
		ASSERT_NE(myAddition.add(10,10), 0);
		ASSERT_GE(myAddition.add(10,10), 30);
}

TEST(TestingAddition, addID) {
    zf::sample::Addition myAddition = zf::sample::Addition();
		ASSERT_EQ(myAddition.addID(1), 43);
}

TEST(TestingAddition, addOne) {
    zf::sample::Addition myAddition = zf::sample::Addition();
		ASSERT_EQ(myAddition.addOne(1), 2);
}

TEST(TestingAddition, failure) {
	  ASSERT_TRUE(false);
}

