#pragma once
#include "base_project.h"

namespace xtdc_command {
  class csharp_console_project : public base_project {
  public:
    explicit csharp_console_project(const xtd::ustring& path) : base_project(path) {}
    
    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::ustring& name) const {
      generate_cmakelists_txt(name, current_path());
    }

  private:
    void create_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name),
        "include(CSharpUtilities)",
        "set(SOURCES",
        "  src/Program.cs",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Program class.",
        "using System;",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the main class.",
        "  class Program {",
        "    /// @brief The main entry point for the application.",
        "    static void Main(string[] args) {",
        "      Console.WriteLine(\"Hello, World!\");",
        "    }",
        "  }",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Program.cs"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines;
      lines.push_back("cmake_minimum_required(VERSION 3.8)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::ustring::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name));
      lines.push_back("include(CSharpUtilities)");
      lines.push_back("set(SOURCES");
      for (auto file : get_csharp_sources(path, path))
        lines.push_back(xtd::ustring::format("  {}", file));
      lines.push_back(")");
      lines.push_back("source_group(src FILES ${SOURCES})");
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_executable(${PROJECT_NAME} ${SOURCES})");

      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
