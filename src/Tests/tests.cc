#include <gtest/gtest.h>

#include "../Model/Object_Handler/Recorder/V_F_Recorder/v_f_parser.h"

s21::ObjectData object_data;

std::string GetWorkingDirectory() {
    char current_working_directory[1024];
    getcwd(current_working_directory, sizeof(current_working_directory));
    return std::string(current_working_directory);
}

TEST(test_1, not_exist_file) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/ASDAD.obj";
	bool exist = s21::VFParser::RecordDataFromFile(file_path, object_data);
  EXPECT_FALSE(exist);
}

TEST(test_2, exist_file) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/Tests/modified_cube_for_test.obj";
	bool exist = s21::VFParser::RecordDataFromFile(file_path, object_data);
	EXPECT_TRUE(exist);
}

TEST(test_3, record_vertex) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/Tests/modified_cube_for_test.obj";
	s21::VFParser::RecordDataFromFile(file_path, object_data);
	EXPECT_TRUE(object_data.vertices[0].x == -1);
	EXPECT_TRUE(object_data.vertices[0].y == -1);
	EXPECT_TRUE(object_data.vertices[0].z == 1);
}

TEST(test_4, record_facet_with_slashes) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/Tests/modified_cube_for_test.obj";
	s21::VFParser::RecordDataFromFile(file_path, object_data);
	EXPECT_TRUE(object_data.facets[0] == 0);
	EXPECT_TRUE(object_data.facets[1] == 1);
	EXPECT_TRUE(object_data.facets[2] == 1);
	EXPECT_TRUE(object_data.facets[3] == 3);
	EXPECT_TRUE(object_data.facets[4] == 3);
	EXPECT_TRUE(object_data.facets[5] == 0);
}

TEST(test_5, record_facet_with_negative_value) {
  std::string current_directory = GetWorkingDirectory();
  std::string file_path = current_directory + "/Tests/modified_cube_for_test.obj";
	s21::VFParser::RecordDataFromFile(file_path, object_data);
	EXPECT_TRUE(object_data.facets[6] == object_data.vertices.size() - 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}