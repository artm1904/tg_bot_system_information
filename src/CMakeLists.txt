cmake_minimum_required(VERSION 3.10)
project(tg_bot_system_information VERSION 0.1.0)


find_package(Boost REQUIRED COMPONENTS system ) 
find_package(nlohmann_json REQUIRED)
find_package(OpenSSL REQUIRED)


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "*.h")


add_executable(tg_bot_system_information
    ${SOURCES}
    ${HEADERS})



target_link_libraries(
    tg_bot_system_information
    PUBLIC
    Boost::system
    OpenSSL::SSL
    OpenSSL::Crypto
    nlohmann_json::nlohmann_json project_options)


