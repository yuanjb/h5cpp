//
// (c) Copyright 2018 DESY,ESS
//
// This file is part of h5cpp.
//
// This library is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation; either version 2.1 of the License, or
// (at your option) any later version.
//
// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty ofMERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
// License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this library; if not, write to the
// Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor
// Boston, MA  02110-1301 USA
// ===========================================================================
//
// Author: Jan Kotanski <jan,kotanski@desy.de>
// Created on: Jul 2, 2018
//
#include <gtest/gtest.h>
#include <h5cpp/hdf5.hpp>

using namespace hdf5;

class H5CppBoolTest : public testing::Test
{
  protected:
    file::File h5py_file_18;
    node::Group root_group_18;
    file::File h5py_file_110;
    node::Group root_group_110;

    virtual void SetUp()
    {
      h5py_file_18 = file::open("./h5cpp_test_1.8_boolattr.h5",file::AccessFlags::READONLY);
      root_group_18 = h5py_file_18.root();
      h5py_file_110 = file::open("./h5cpp_test_1.10_boolattr.h5",file::AccessFlags::READONLY);
      root_group_110 = h5py_file_110.root();
    }

};

#ifndef _MSC_VER
TEST_F(H5CppBoolTest, test_read_scalar_bool_18)
{
  auto attrue =  root_group_18.attributes["bool_scalar_true"];
  bool buffer;
  attrue.read(buffer);
  EXPECT_EQ(buffer, true);
  bool buffer2;
  auto atfalse =  root_group_18.attributes["bool_scalar_false"];
  atfalse.read(buffer2);
  EXPECT_EQ(buffer2, false);
}

TEST_F(H5CppBoolTest, test_read_simple_bool_18)
{
  auto attrue =  root_group_18.attributes["bool_simple_true"];
  bool buffer;
  attrue.read(buffer);
  EXPECT_EQ(buffer, true);
  bool buffer2;
  auto atfalse =  root_group_18.attributes["bool_simple_false"];
  atfalse.read(buffer2);
  EXPECT_EQ(buffer2, false);
}

TEST_F(H5CppBoolTest, test_read_scalar_bool_110)
{
  auto attrue =  root_group_110.attributes["bool_scalar_true"];
  bool buffer;
  attrue.read(buffer);
  EXPECT_EQ(buffer, true);
  bool buffer2;
  auto atfalse =  root_group_110.attributes["bool_scalar_false"];
  atfalse.read(buffer2);
  EXPECT_EQ(buffer2, false);
}

TEST_F(H5CppBoolTest, test_read_simple_bool_110)
{
  auto attrue =  root_group_110.attributes["bool_simple_true"];
  bool buffer;
  attrue.read(buffer);
  EXPECT_EQ(buffer, true);
  bool buffer2;
  auto atfalse =  root_group_110.attributes["bool_simple_false"];
  atfalse.read(buffer2);
  EXPECT_EQ(buffer2, false);
}

#endif
