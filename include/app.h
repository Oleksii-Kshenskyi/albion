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

            App& version(std::string version);
            App& author(std::string author);

        private:
            std::string app_name;
            std::string app_version;
            std::string app_author;
    };

    App app(std::string app_name);
}