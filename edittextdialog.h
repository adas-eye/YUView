/*  YUView - YUV player with advanced analytics toolset
*   Copyright (C) 2015  Institut für Nachrichtentechnik
*                       RWTH Aachen University, GERMANY
*
*   YUView is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   YUView is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with YUView.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EditTextDialog_H
#define EditTextDialog_H

#include <QDialog>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include "playlistitemtext.h"

namespace Ui {
class EditTextDialog;
}

class EditTextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditTextDialog(QWidget *parent = 0);
    ~EditTextDialog();
    void loadItemStettings(PlaylistItemText* item);
    QFont getFont() {return currentFont;}
    double getDuration() {return currentDuration;}
    QString getText() {return currentText;}
    QColor getColor() {return currentColor;}
public slots:
    void editFont();
    void saveState();
private slots:
    void on_editColor_clicked();

    void on_textEdit_textChanged();

    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::EditTextDialog *ui;
    PlaylistItemText* currentItem;
    QFont currentFont;
    QString currentText;
    QColor currentColor;
    double currentDuration;
};

#endif // EditTextDialog_H