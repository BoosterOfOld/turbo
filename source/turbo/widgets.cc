#include "widgets.h"
#include <ctime>

TClockView::TClockView( TRect& r ) :
    TView(r)
{
    strcpy(lastTime, "        ");
    strcpy(curTime, "        ");
}


void TClockView::draw()
{
    TDrawBuffer buf;
    uchar c = getColor(2);

    buf.moveChar(0, ' ', c, size.x);
    buf.moveStr(0, curTime, c);
    writeLine(0, 0, size.x, 1, buf);
}


void TClockView::update()
{
    time_t t = time(0);
    char *date = ctime(&t);

    date[19] = '\0';
    strcpy(curTime, &date[11]);

    if (strcmp(lastTime, curTime)) {
        drawView();
        strcpy(lastTime, curTime);
    }
}

//

TLabelX::TLabelX(TRect& r, char const*text) : TView(r)
{
    this->label = std::unique_ptr<char []>(new char[strlen(text)]);
    strcpy(this->label.get(), text);
}

/*
enum TextStyle : uchar
{
    sNormal,      0          - beige on orange
    sSelection,   1          - blue on beige
    sWhitespace,  2          - black on beige
    sCtrlChar,    3          - brown on beige
    sLineNums,    4          - red on beige
    sKeyword1,    5          - black on green
    sKeyword2,    6          - brown on green
    sMisc,              7    - red on green
    sPreprocessor,      8    - white on blue
    sOperator,          9    - white on blue
    sComment,           10   - gray on blue
    sStringLiteral,     11   - green on blue
    sCharLiteral,       12   - -||-
    sNumberLiteral,     13   - beige on blue
    sEscapeSequence,    14   - blue on beige
    sError,             15   - white on blue
    sBraceMatch,        16   - white on green-blue
    sReplaceHighlight,  17   - -||-
    21 - yellow on green-blue

};*/

void TLabelX::draw()
{
    TDrawBuffer buf;
    uchar c = getColor(5); // 5 good green 7 red on green

    //buf.moveChar(0, ' ', c, size.x);
    buf.moveStr(0, this->label.get(), c);
    writeLine(0, 0, size.x, 1, buf);
}

