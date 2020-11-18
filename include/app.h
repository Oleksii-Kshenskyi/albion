#include <string>

namespace albion
{
    class App
    {
        public:
            App(App&& another);
            App(std::string app_name);
            App& operator=(App&& another);

            std::string get_name();
            std::string get_version();
            std::string get_author();
            std::string get_about();

            App&& version(std::string version);
            App&& author(std::string author);
            App&& about(std::string about);

        private:
            std::string app_name;
            std::string app_version;
            std::string app_author;
            std::string app_about;
    };

    App app(std::string app_name);
}