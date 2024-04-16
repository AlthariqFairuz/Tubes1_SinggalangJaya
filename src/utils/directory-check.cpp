#include "directory-check.hpp"

bool isParentDirValid(const std::string &path)
{
  std::filesystem::path p(path);

  return std::filesystem::exists(p.parent_path());
}