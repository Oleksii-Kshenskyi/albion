#include "app.h"

albion::App albion::app(std::string app_name)
{
    return App(app_name);
}

albion::App::App(App&& another)
{
    this->app_name = another.app_name;
    this->app_version = another.app_version;
    this->app_author = another.app_author;

    another.app_name.clear();
    another.app_version.clear();
    another.app_author.clear();
}

albion::App::App(std::string app_name)
{
    this->app_name = app_name;
}

albion::App& albion::App::operator=(albion::App&& another)
{
    if(this != &another)
    {
        this->app_name = another.app_name;
        this->app_version = another.app_version;
        this->app_author = another.app_author;

        another.app_name.clear();
        another.app_version.clear();
        another.app_author.clear();
    }

    return *this;
}

albion::App& albion::App::version(std::string version)
{
    this->app_version = version;

    return *this;
}

albion::App& albion::App::author(std::string author)
{
    this->app_author = author;

    return *this;
}

std::string albion::App::get_name()
{
    return this->app_name;
}

std::string albion::App::get_version()
{
    return this->app_version;
}

std::string albion::App::get_author()
{
    return this->app_author;
}