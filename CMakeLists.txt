cmake_minimum_required(VERSION 3.24)
project(SFML_Template)

set(CMAKE_CXX_STANDARD 17)

add_executable(SFML_Template main.cpp MultiText.h MultiText.cpp Letter.h Letter.cpp Application.h Application.cpp Font.cpp FontEnum.h Constants.h Box.h Box.cpp StatesEnum.h States.h States.cpp GUIComponent.h GUIComponent.cpp EventHandler.h EventHandler.cpp Helper.h Helper.cpp Snapshot.h Snapshot.cpp SnapshotInterface.h KeyboardShortcut.h KeyboardShortcut.cpp MouseEvents.h MouseEvents.cpp History.h History.cpp TextInput.h TextInput.cpp Cursor.h Cursor.cpp Label.h Label.cpp Heap.h Heap.cpp WordSort.h WordSort.cpp FailedList.h FailedList.cpp DropdownMenus.h DropdownMenus.cpp HowToUse.h HowToUse.cpp MenuBar.h MenuBar.cpp FileTree.h FileTree.cpp Node.h fileDropdown.h fileDropdown.cpp File.h File.cpp FileItem.h FileItem.cpp Image.cpp NaryTree.h NaryTree.cpp treeNode.h treeNode.cpp)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(SFML_Template sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
