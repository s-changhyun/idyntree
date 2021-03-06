/*
 * Copyright (C) 2015 Fondazione Istituto Italiano di Tecnologia
 *
 * Licensed under either the GNU Lesser General Public License v3.0 :
 * https://www.gnu.org/licenses/lgpl-3.0.html
 * or the GNU Lesser General Public License v2.1 :
 * https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
 * at your option.
 */

#include <iDynTree/Core/VectorDynSize.h>
#include <iDynTree/Core/TestUtils.h>


using namespace iDynTree;

int main()
{
    VectorDynSize vec;

    ASSERT_EQUAL_DOUBLE(vec.size(),0);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),0);

    vec.resize(10);

    ASSERT_EQUAL_DOUBLE(vec.size(),10);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),10);

    vec.reserve(20);

    ASSERT_EQUAL_DOUBLE(vec.size(),10);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),20);

    vec.reserve(30);

    ASSERT_EQUAL_DOUBLE(vec.size(),10);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),30);

    vec.resize(15);

    ASSERT_EQUAL_DOUBLE(vec.size(),15);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),30);

    vec.shrink_to_fit();

    ASSERT_EQUAL_DOUBLE(vec.size(),15);
    ASSERT_EQUAL_DOUBLE(vec.capacity(),15);
}
