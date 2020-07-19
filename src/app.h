#ifndef TVEDIT_APP_H
#define TVEDIT_APP_H

#define Uses_TApplication
#include <tvision/tv.h>

#include <string_view>
#include <unordered_map>
#include <vector>

class EditorWindow;

namespace tvedit {

struct TVEditApp: public TApplication {

    std::unordered_map<std::string, uint> editorTitles;

    void fileNew();
    void fileOpen();
    bool openEditor(std::string_view fileName);
    void setEditorTitle(EditorWindow *w);

    TVEditApp();
    static TMenuBar* initMenuBar(TRect r);
    static TStatusLine* initStatusLine(TRect r);
    void handleEvent(TEvent& event) override;

};

extern TVEditApp *app;

}

#endif
