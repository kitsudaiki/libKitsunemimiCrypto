/**
 *  @file       main.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include <iostream>
#include <vector>

#include <common_test.h>
#include <hashes_test.h>
#include <signing_test.h>
#include <symmetric_encryption_test.h>

int main()
{
    Kitsunemimi::Crypto::Common_Test();
    Kitsunemimi::Crypto::Hashes_Test();
    Kitsunemimi::Crypto::Signing_Test();
    Kitsunemimi::Crypto::Symmetric_Encryption_Test();

    return 0;
}

