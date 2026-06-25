// SPDX-License-Identifier: GPL-3.0-only
/*
 *  Prism Launcher - Minecraft Launcher
 *  Copyright (C) 2024 Tayou <git@tayou.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * This file incorporates work covered by the following copyright and
 * permission notice:
 *
 *      Copyright 2013-2021 MultiMC Contributors
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *          http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 */
#include "BrightTheme.h"

#include <QObject>

QString BrightTheme::id()
{
    return "bright";
}

QString BrightTheme::name()
{
    return QObject::tr("Bright");
}

QPalette BrightTheme::colorScheme()
{
    QPalette brightPalette;
    brightPalette.setColor(QPalette::Window, QColor(255, 255, 255));
    brightPalette.setColor(QPalette::WindowText, QColor(17, 17, 17));
    brightPalette.setColor(QPalette::Base, QColor(250, 250, 250));
    brightPalette.setColor(QPalette::AlternateBase, QColor(240, 240, 240));
    brightPalette.setColor(QPalette::ToolTipBase, QColor(17, 17, 17));
    brightPalette.setColor(QPalette::ToolTipText, QColor(255, 255, 255));
    brightPalette.setColor(QPalette::Text, Qt::black);
    brightPalette.setColor(QPalette::Button, QColor(249, 249, 249));
    brightPalette.setColor(QPalette::ButtonText, Qt::black);
    brightPalette.setColor(QPalette::BrightText, Qt::red);
    brightPalette.setColor(QPalette::Link, QColor(109, 40, 217));     // #6D28D9 - LauncherVit brand purple (light)
    brightPalette.setColor(QPalette::Highlight, QColor(126, 34, 206)); // #7E22CE - deep brand purple (AA with white)
    brightPalette.setColor(QPalette::HighlightedText, Qt::white);
    return fadeInactive(brightPalette, fadeAmount(), fadeColor());
}

double BrightTheme::fadeAmount()
{
    return 0.5;
}

QColor BrightTheme::fadeColor()
{
    return QColor(255, 255, 255);
}

bool BrightTheme::hasStyleSheet()
{
    return true;
}

QString BrightTheme::appStyleSheet()
{
    // LauncherVit professional light theme — deep-purple accented, spacious, modern. Widget-scoped.
    return QStringLiteral(R"qss(
/* ---- Toolbars ---- */
QToolBar { spacing: 6px; padding: 6px; border: none; }
QToolBar::separator { background: rgba(126,34,206,0.25); width: 1px; height: 1px; margin: 4px 8px; }
QToolButton { border: 1px solid transparent; border-radius: 8px; padding: 6px 10px; }
QToolButton:hover { background: rgba(168,85,247,0.14); border-color: rgba(126,34,206,0.35); }
QToolButton:pressed, QToolButton:checked { background: rgba(168,85,247,0.24); }
QToolButton::menu-button { border: none; width: 18px; border-top-right-radius: 8px; border-bottom-right-radius: 8px; }

/* ---- Instance rail (vertical, main window): wide, spacious, text-only ---- */
WideBar#instanceToolBar { padding: 8px; }
WideBar#instanceToolBar QToolButton { min-width: 176px; min-height: 22px; padding: 9px 16px; border-radius: 8px; font-size: 10pt; text-align: left; }
/* The instance icon and name buttons scale their content to the button rect — keep them centered with no heavy padding so the icon isn't clipped. */
WideBar#instanceToolBar QToolButton#changeIconButton, WideBar#instanceToolBar QToolButton#renameButton { min-width: 0px; padding: 3px; text-align: center; }
QToolButton#actionLaunchInstance { background: #7E22CE; color: #ffffff; border-radius: 10px; padding: 13px 16px; font-weight: 700; font-size: 11pt; }
QToolButton#actionLaunchInstance:hover { background: #9333EA; }
QToolButton#actionLaunchInstance:pressed { background: #6D28D9; }
QToolButton#actionLaunchInstance:disabled { background: rgba(126,34,206,0.28); color: rgba(255,255,255,0.7); }

/* Account button (top-right): same width as the instance rail, sits above it */
/* ---- Left navigation rail (mainToolBar) ---- */
QToolBar#mainToolBar { background: rgba(0,0,0,0.06); border: none; border-top-right-radius: 16px; border-bottom-right-radius: 16px; padding: 12px 8px; spacing: 8px; }
QToolBar#mainToolBar QToolButton { min-width: 42px; min-height: 42px; padding: 8px; border-radius: 12px; }
QToolBar#mainToolBar QToolButton:hover { background: rgba(168,85,247,0.16); border-color: transparent; }
QToolBar#mainToolBar QToolButton:checked, QToolBar#mainToolBar QToolButton:pressed { background: #7E22CE; }
QToolBar#mainToolBar QToolButton#accountMenuButton { min-width: 42px; min-height: 42px; padding: 8px; border-radius: 21px; }
QToolBar#mainToolBar QToolButton::menu-indicator, QToolBar#mainToolBar QToolButton::menu-arrow { image: none; width: 0px; height: 0px; }
QToolBar#mainToolBar::separator { background: rgba(0,0,0,0.08); height: 1px; margin: 6px 10px; }

/* ---- Custom title bar ---- */
QToolBar#titleToolBar { padding: 0px; margin: 0px; border: none; spacing: 0px; background: #ffffff; }
QWidget#customTitleBar { background: #ffffff; }
QLabel#titleBarLabel { font-weight: 600; color: #111111; }
QToolButton#winBtnMin, QToolButton#winBtnMax, QToolButton#winBtnClose { border: none; border-radius: 6px; background: transparent; color: rgba(0,0,0,0.6); font-size: 12pt; }
QToolButton#winBtnMin:hover, QToolButton#winBtnMax:hover { background: rgba(168,85,247,0.20); }
QToolButton#winBtnClose:hover { background: #e11d48; color: #ffffff; }

/* ---- Push buttons ---- */
QPushButton { border: 1px solid rgba(0,0,0,0.15); border-radius: 7px; padding: 7px 16px; min-height: 18px; }
QPushButton:hover { border-color: #7E22CE; background: rgba(168,85,247,0.10); }
QPushButton:pressed { background: rgba(168,85,247,0.18); }
QPushButton:default { background: #7E22CE; color: #fff; border-color: #7E22CE; font-weight: 600; }
QPushButton:default:hover { background: #9333EA; }
QPushButton:disabled { color: rgba(0,0,0,0.35); border-color: rgba(0,0,0,0.08); }

/* ---- Inputs ---- */
QLineEdit, QPlainTextEdit, QTextEdit, QSpinBox, QDoubleSpinBox, QComboBox {
  border: 1px solid rgba(0,0,0,0.18); border-radius: 7px; padding: 6px 9px;
  background: #ffffff; selection-background-color: #7E22CE; selection-color: #fff; }
QLineEdit:focus, QPlainTextEdit:focus, QTextEdit:focus, QSpinBox:focus, QDoubleSpinBox:focus, QComboBox:focus { border-color: #7E22CE; }
QComboBox::drop-down { border: none; width: 22px; }
QComboBox QAbstractItemView { border: 1px solid rgba(126,34,206,0.5); border-radius: 6px; background: #ffffff; selection-background-color: #7E22CE; selection-color: #fff; padding: 2px; }

/* ---- Lists / trees / tables ---- */
QListView, QTreeView, QTableView { border: 1px solid rgba(0,0,0,0.10); border-radius: 8px; background: #ffffff; outline: none; }
QListView::item { padding: 5px 6px; border-radius: 6px; }
QTreeView::item, QTableView::item { padding: 6px 6px; border-radius: 0px; }
QListView::item:hover, QTreeView::item:hover, QTableView::item:hover { background: rgba(168,85,247,0.10); }
QListView::item:selected, QTreeView::item:selected, QTableView::item:selected { background: #7E22CE; color: #fff; }
QHeaderView::section { background: rgba(0,0,0,0.04); padding: 7px 10px; border: none; border-right: 1px solid rgba(0,0,0,0.06); font-weight: 600; }

/* ---- Tabs ---- */
QTabWidget::pane { border: 1px solid rgba(0,0,0,0.10); border-radius: 8px; top: -1px; }
QTabBar::tab { padding: 8px 16px; margin-right: 2px; border: none; color: rgba(0,0,0,0.55); }
QTabBar::tab:hover { color: #000; }
QTabBar::tab:selected { color: #7E22CE; border-bottom: 2px solid #7E22CE; }

/* ---- Group boxes ---- */
QGroupBox { border: 1px solid rgba(0,0,0,0.12); border-radius: 8px; margin-top: 16px; padding: 12px 10px 10px 10px; }
QGroupBox::title { subcontrol-origin: margin; left: 12px; padding: 0 5px; color: #7E22CE; font-weight: 600; }

/* ---- Progress ---- */
QProgressBar { border: 1px solid rgba(0,0,0,0.12); border-radius: 6px; text-align: center; min-height: 16px; }
QProgressBar::chunk { background-color: #7E22CE; border-radius: 5px; margin: 1px; }

/* ---- Scrollbars ---- */
QScrollBar:vertical { background: transparent; width: 12px; margin: 2px; }
QScrollBar::handle:vertical { background: rgba(126,34,206,0.35); border-radius: 5px; min-height: 32px; }
QScrollBar::handle:vertical:hover { background: rgba(126,34,206,0.65); }
QScrollBar:horizontal { background: transparent; height: 12px; margin: 2px; }
QScrollBar::handle:horizontal { background: rgba(126,34,206,0.35); border-radius: 5px; min-width: 32px; }
QScrollBar::handle:horizontal:hover { background: rgba(126,34,206,0.65); }
QScrollBar::add-line, QScrollBar::sub-line { height: 0; width: 0; background: none; border: none; }
QScrollBar::add-page, QScrollBar::sub-page { background: transparent; }

/* ---- Menus ---- */
QMenu { border: 1px solid rgba(126,34,206,0.35); border-radius: 8px; padding: 6px; }
QMenu::item { padding: 7px 26px; border-radius: 6px; }
QMenu::item:selected { background: #7E22CE; color: #fff; }
QMenu::separator { height: 1px; background: rgba(0,0,0,0.08); margin: 5px 8px; }
QMenuBar { background: transparent; }
QMenuBar::item { padding: 5px 11px; border-radius: 6px; }
QMenuBar::item:selected { background: rgba(168,85,247,0.18); }

/* ---- Status & news bars ---- */
QStatusBar { border-top: 1px solid rgba(0,0,0,0.08); padding: 3px 10px; }
QStatusBar QLabel { padding: 0 8px; }
QStatusBar::item { border: none; }
QToolBar#newsToolBar { border: none; }
QToolBar#newsToolBar QToolButton { border: none; background: transparent; color: #7E22CE; padding: 4px 8px; }
QToolBar#newsToolBar QToolButton:hover { text-decoration: underline; }

/* ---- Tooltip ---- */
QToolTip { color: #111111; background-color: #ffffff; border: 1px solid #7E22CE; border-radius: 6px; padding: 5px 8px; }
)qss");
}
QString BrightTheme::tooltip()
{
    return QString();
}
