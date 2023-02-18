#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <QObject>
#include <QStandardItem>

enum PaletteItemDataRole
{
    TextBackground_Dark_01 = Qt::ItemDataRole::UserRole + 1,
    TextBackground_Light_01,
    TextBackground_Dark_02,
    TextBackground_Light_02,
    Accent_01,
    Accent_02,
    Accent_03,
    Accent_04,
    Accent_05,
    Accent_06,
    Hyperlink,
    Followed_Hyperlink
};

#define ColorSquareWidth 14 //px
#define ColorSquareBorderWidth 1 //px

static QList<QStandardItem *> MSOfficePallets = {
    new QStandardItem("Office"),                // 01
    new QStandardItem("Office 2007 - 2010"),    // 02
    new QStandardItem("Grayscale"),             // 03
    new QStandardItem("Blue Warm"),             // 04
    new QStandardItem("Blue"),                  // 05
    new QStandardItem("Blue II"),               // 06
    new QStandardItem("Blue Green"),            // 07
    new QStandardItem("Green"),                 // 08
    new QStandardItem("Green Yellow"),          // 09
    new QStandardItem("Yellow"),                // 10
    new QStandardItem("Yellow Orange"),         // 11
    new QStandardItem("Orange"),                // 12
    new QStandardItem("Orange Red"),            // 13
    new QStandardItem("Red"),                   // 14
    new QStandardItem("Red Violet"),            // 15
    new QStandardItem("Violet"),                // 16
    new QStandardItem("Violet II"),             // 17
    new QStandardItem("Median"),                // 18
    new QStandardItem("Paper"),                 // 19
    new QStandardItem("Marquee"),               // 20
    new QStandardItem("Slipstream"),            // 21
    new QStandardItem("Aspect")                 // 22
};

static void FillMSOfficePalettes()
{
    // Office
    MSOfficePallets[ 0]->setData(QColor( 68,  84, 106), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[ 0]->setData(QColor(231, 230, 230), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[ 0]->setData(QColor( 68, 114, 196), PaletteItemDataRole::Accent_01);
    MSOfficePallets[ 0]->setData(QColor(237, 125,  49), PaletteItemDataRole::Accent_02);
    MSOfficePallets[ 0]->setData(QColor(165, 165, 165), PaletteItemDataRole::Accent_03);
    MSOfficePallets[ 0]->setData(QColor(255, 192,   0), PaletteItemDataRole::Accent_04);
    MSOfficePallets[ 0]->setData(QColor( 91, 155, 213), PaletteItemDataRole::Accent_05);
    MSOfficePallets[ 0]->setData(QColor(112, 173,  71), PaletteItemDataRole::Accent_06);
    MSOfficePallets[ 0]->setData(Qt::CheckState::Checked, Qt::ItemDataRole::CheckStateRole);
    // Office 2007 - 2010
    MSOfficePallets[ 1]->setData(QColor( 31,  73, 125), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[ 1]->setData(QColor(238, 236, 225), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[ 1]->setData(QColor( 79, 129, 189), PaletteItemDataRole::Accent_01);
    MSOfficePallets[ 1]->setData(QColor(192,  80,  77), PaletteItemDataRole::Accent_02);
    MSOfficePallets[ 1]->setData(QColor(155, 187,  89), PaletteItemDataRole::Accent_03);
    MSOfficePallets[ 1]->setData(QColor(128, 100, 162), PaletteItemDataRole::Accent_04);
    MSOfficePallets[ 1]->setData(QColor( 75, 172, 198), PaletteItemDataRole::Accent_05);
    MSOfficePallets[ 1]->setData(QColor(247, 150,  70), PaletteItemDataRole::Accent_06);
    MSOfficePallets[ 1]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Grayscale
    MSOfficePallets[ 2]->setData(QColor(  0,   0,   0), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[ 2]->setData(QColor(248, 248, 248), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[ 2]->setData(QColor(221, 221, 221), PaletteItemDataRole::Accent_01);
    MSOfficePallets[ 2]->setData(QColor(178, 178, 178), PaletteItemDataRole::Accent_02);
    MSOfficePallets[ 2]->setData(QColor(150, 150, 150), PaletteItemDataRole::Accent_03);
    MSOfficePallets[ 2]->setData(QColor(128, 128, 128), PaletteItemDataRole::Accent_04);
    MSOfficePallets[ 2]->setData(QColor( 95,  95,  95), PaletteItemDataRole::Accent_05);
    MSOfficePallets[ 2]->setData(QColor( 77,  77,  77), PaletteItemDataRole::Accent_06);
    MSOfficePallets[ 2]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Blue Warm
    MSOfficePallets[ 3]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[ 3]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[ 3]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[ 3]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[ 3]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[ 3]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[ 3]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[ 3]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[ 3]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Blue
    MSOfficePallets[ 4]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[ 4]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[ 4]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[ 4]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[ 4]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[ 4]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[ 4]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[ 4]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[ 4]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Blue II
    MSOfficePallets[ 5]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[ 5]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[ 5]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[ 5]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[ 5]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[ 5]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[ 5]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[ 5]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[ 5]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Blue Green
    MSOfficePallets[ 6]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[ 6]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[ 6]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[ 6]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[ 6]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[ 6]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[ 6]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[ 6]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[ 6]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Green
    MSOfficePallets[ 7]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[ 7]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[ 7]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[ 7]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[ 7]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[ 7]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[ 7]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[ 7]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[ 7]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Green Yellow
    MSOfficePallets[ 8]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[ 8]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[ 8]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[ 8]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[ 8]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[ 8]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[ 8]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[ 8]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[ 8]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Yellow
    MSOfficePallets[ 9]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[ 9]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[ 9]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[ 9]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[ 9]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[ 9]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[ 9]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[ 9]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[ 9]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Yellow Orange
    MSOfficePallets[10]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[10]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[10]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[10]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[10]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[10]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[10]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[10]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[10]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Orange
    MSOfficePallets[11]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[11]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[11]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[11]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[11]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[11]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[11]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[11]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[11]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Orange Red
    MSOfficePallets[12]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[12]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[12]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[12]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[12]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[12]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[12]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[12]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[12]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Red
    MSOfficePallets[13]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[13]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[13]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[13]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[13]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[13]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[13]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[13]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[13]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Red Violet
    MSOfficePallets[14]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[14]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[14]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[14]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[14]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[14]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[14]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[14]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[14]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Violet
    MSOfficePallets[15]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[15]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[15]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[15]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[15]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[15]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[15]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[15]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[15]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Violet II
    MSOfficePallets[16]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[16]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[16]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[16]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[16]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[16]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[16]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[16]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[16]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Median
    MSOfficePallets[17]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[17]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[17]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[17]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[17]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[17]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[17]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[17]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[17]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Paper
    MSOfficePallets[18]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[18]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[18]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[18]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[18]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[18]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[18]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[18]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[18]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Marquee
    MSOfficePallets[19]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[19]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[19]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[19]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[19]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[19]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[19]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[19]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[19]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Slipstream
    MSOfficePallets[20]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[20]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[20]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[20]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[20]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[20]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[20]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[20]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[20]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
    // Aspect
    MSOfficePallets[21]->setData(QColor( 50,  50,  50), PaletteItemDataRole::TextBackground_Dark_02);
    MSOfficePallets[21]->setData(QColor(227, 222, 209), PaletteItemDataRole::TextBackground_Light_02);
    MSOfficePallets[21]->setData(QColor(240, 127,   9), PaletteItemDataRole::Accent_01);
    MSOfficePallets[21]->setData(QColor(159,  41,  54), PaletteItemDataRole::Accent_02);
    MSOfficePallets[21]->setData(QColor( 27,  88, 124), PaletteItemDataRole::Accent_03);
    MSOfficePallets[21]->setData(QColor( 78, 133,  66), PaletteItemDataRole::Accent_04);
    MSOfficePallets[21]->setData(QColor( 96,  72, 120), PaletteItemDataRole::Accent_05);
    MSOfficePallets[21]->setData(QColor(193, 152,  89), PaletteItemDataRole::Accent_06);
    MSOfficePallets[21]->setData(Qt::CheckState::Unchecked, Qt::ItemDataRole::CheckStateRole);
}

static QColor ColorSquareBorderColor = QColor(134, 134, 134);

static QColor ColorPaletteCheckedBorderColor = QColor(150, 150, 150);

static QColor ColorPaletteCheckedStateBackgroundColor = QColor(197, 197, 197);

static QColor ColorPaletteHoveredBackgroundColor = QColor(197, 197, 197);

static QColor ColorPalettePressedBorderColor = QColor(150, 150, 150);

#endif // DEFINITIONS_H
