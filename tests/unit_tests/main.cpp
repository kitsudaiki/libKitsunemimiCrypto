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
    Kitsunemimi::Common_Test();
    Kitsunemimi::Hashes_Test();
    Kitsunemimi::Signing_Test();
    Kitsunemimi::Symmetric_Encryption_Test();

    return 0;
}

