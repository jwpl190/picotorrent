#pragma once

#include <memory>
#include <vector>
#include <windows.h>

#include <picotorrent/export.hpp>

namespace picotorrent
{
    struct plugin_config_window;

namespace extensibility
{
    class plugin_host;

    struct plugin_metadata
    {
        std::string name;
        std::string version;
        std::shared_ptr<picotorrent::plugin_config_window> config_window;
    };

    class plugin_engine
    {
    public:
        DLL_EXPORT void load_all(const std::shared_ptr<plugin_host> &host);
        DLL_EXPORT void unload_all();
        DLL_EXPORT std::vector<plugin_metadata> get_plugins();

    private:
        class plugin_handle;
        std::vector<std::shared_ptr<plugin_handle>> plugins_;
    };
}
}