// SPDX-License-Identifier: GPL-3.0-only
/*
 *  Prism Launcher - Minecraft Launcher
 *  Copyright (C) 2024 Tayou <git@tayou.org>
 *  Copyright (C) 2024 TheKodeToad <TheKodeToad@proton.me>
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
#include "DarkTheme.h"

#include <QObject>

QString DarkTheme::id()
{
    return "dark";
}

QString DarkTheme::name()
{
    return QObject::tr("Dark");
}

QPalette DarkTheme::colorScheme()
{
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(49, 49, 49));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(34, 34, 34));
    darkPalette.setColor(QPalette::AlternateBase, QColor(42, 42, 42));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(48, 48, 48));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(192, 132, 252));     // #C084FC - LauncherVit brand purple
    darkPalette.setColor(QPalette::Highlight, QColor(147, 51, 234));  // #9333EA - brand purple (AA contrast with white)
    darkPalette.setColor(QPalette::HighlightedText, Qt::white);
    darkPalette.setColor(QPalette::PlaceholderText, Qt::darkGray);
    return fadeInactive(darkPalette, fadeAmount(), fadeColor());
}

double DarkTheme::fadeAmount()
{
    return 0.5;
}

QColor DarkTheme::fadeColor()
{
    return QColor(49, 49, 49);
}

bool DarkTheme::hasStyleSheet()
{
    return true;
}

QString DarkTheme::appStyleSheet()
{
    // LauncherVit professional dark theme — purple-accented, spacious, modern. Widget-scoped.
    return QStringLiteral(R"qss(
/* ---- Toolbars ---- */
QToolBar { spacing: 6px; padding: 6px; border: none; }
QToolBar::separator { background: rgba(168,85,247,0.30); width: 1px; height: 1px; margin: 4px 8px; }
QToolButton { border: 1px solid transparent; border-radius: 8px; padding: 6px 10px; }
QToolButton:hover { background: rgba(168,85,247,0.16); border-color: rgba(168,85,247,0.40); }
QToolButton:pressed, QToolButton:checked { background: rgba(168,85,247,0.28); }
QToolButton::menu-button { border: none; width: 18px; border-top-right-radius: 8px; border-bottom-right-radius: 8px; }

/* ---- Instance rail (vertical, main window): wide, spacious, text-only ---- */
WideBar#instanceToolBar { padding: 8px; }
WideBar#instanceToolBar QToolButton { min-width: 176px; min-height: 22px; padding: 9px 16px; border-radius: 8px; font-size: 10pt; text-align: left; }
QToolButton#actionLaunchInstance { background: #A855F7; color: #ffffff; border-radius: 10px; padding: 13px 16px; font-weight: 700; font-size: 11pt; }
QToolButton#actionLaunchInstance:hover { background: #9333EA; }
QToolButton#actionLaunchInstance:pressed { background: #7E22CE; }
QToolButton#actionLaunchInstance:disabled { background: rgba(168,85,247,0.28); color: rgba(255,255,255,0.5); }

/* Account button (top-right): same width as the instance rail, sits above it */
QToolButton#accountMenuButton { min-width: 176px; padding: 8px 16px; border-radius: 8px; text-align: center; font-weight: 600; }
QToolButton#accountMenuButton::menu-indicator, QToolButton#accountMenuButton::menu-arrow { image: none; width: 0px; height: 0px; }

/* ---- Push buttons ---- */
QPushButton { border: 1px solid rgba(255,255,255,0.14); border-radius: 7px; padding: 7px 16px; min-height: 18px; }
QPushButton:hover { border-color: #A855F7; background: rgba(168,85,247,0.12); }
QPushButton:pressed { background: rgba(168,85,247,0.22); }
QPushButton:default { background: #A855F7; color: #fff; border-color: #A855F7; font-weight: 600; }
QPushButton:default:hover { background: #9333EA; }
QPushButton:disabled { color: rgba(255,255,255,0.4); border-color: rgba(255,255,255,0.07); }

/* ---- Inputs ---- */
QLineEdit, QPlainTextEdit, QTextEdit, QSpinBox, QDoubleSpinBox, QComboBox {
  border: 1px solid rgba(255,255,255,0.14); border-radius: 7px; padding: 6px 9px;
  background: rgba(0,0,0,0.22); selection-background-color: #9333EA; selection-color: #fff; }
QLineEdit:focus, QPlainTextEdit:focus, QTextEdit:focus, QSpinBox:focus, QDoubleSpinBox:focus, QComboBox:focus { border-color: #A855F7; }
QComboBox::drop-down { border: none; width: 22px; }
QComboBox QAbstractItemView { border: 1px solid rgba(168,85,247,0.5); border-radius: 6px; background: #2a2a2a; selection-background-color: #9333EA; padding: 2px; }

/* ---- Lists / trees / tables ---- */
QListView, QTreeView, QTableView { border: 1px solid rgba(255,255,255,0.08); border-radius: 8px; background: rgba(0,0,0,0.16); outline: none; }
QListView::item { padding: 5px 6px; border-radius: 6px; }
QTreeView::item, QTableView::item { padding: 6px 6px; border-radius: 0px; }
QListView::item:hover, QTreeView::item:hover, QTableView::item:hover { background: rgba(168,85,247,0.12); }
QListView::item:selected, QTreeView::item:selected, QTableView::item:selected { background: #9333EA; color: #fff; }
QHeaderView::section { background: rgba(255,255,255,0.04); padding: 7px 10px; border: none; border-right: 1px solid rgba(255,255,255,0.06); font-weight: 600; }
QTreeView::branch { background: transparent; }

/* ---- Tabs ---- */
QTabWidget::pane { border: 1px solid rgba(255,255,255,0.10); border-radius: 8px; top: -1px; }
QTabBar::tab { padding: 8px 16px; margin-right: 2px; border: none; color: rgba(255,255,255,0.65); }
QTabBar::tab:hover { color: #fff; }
QTabBar::tab:selected { color: #fff; border-bottom: 2px solid #A855F7; }

/* ---- Group boxes ---- */
QGroupBox { border: 1px solid rgba(255,255,255,0.10); border-radius: 8px; margin-top: 16px; padding: 12px 10px 10px 10px; }
QGroupBox::title { subcontrol-origin: margin; left: 12px; padding: 0 5px; color: #C084FC; font-weight: 600; }

/* ---- Progress ---- */
QProgressBar { border: 1px solid rgba(255,255,255,0.12); border-radius: 6px; text-align: center; min-height: 16px; }
QProgressBar::chunk { background-color: #A855F7; border-radius: 5px; margin: 1px; }

/* ---- Scrollbars: slim, modern ---- */
QScrollBar:vertical { background: transparent; width: 12px; margin: 2px; }
QScrollBar::handle:vertical { background: rgba(168,85,247,0.45); border-radius: 5px; min-height: 32px; }
QScrollBar::handle:vertical:hover { background: rgba(168,85,247,0.75); }
QScrollBar:horizontal { background: transparent; height: 12px; margin: 2px; }
QScrollBar::handle:horizontal { background: rgba(168,85,247,0.45); border-radius: 5px; min-width: 32px; }
QScrollBar::handle:horizontal:hover { background: rgba(168,85,247,0.75); }
QScrollBar::add-line, QScrollBar::sub-line { height: 0; width: 0; background: none; border: none; }
QScrollBar::add-page, QScrollBar::sub-page { background: transparent; }

/* ---- Menus ---- */
QMenu { border: 1px solid rgba(168,85,247,0.4); border-radius: 8px; padding: 6px; }
QMenu::item { padding: 7px 26px; border-radius: 6px; }
QMenu::item:selected { background: #9333EA; color: #fff; }
QMenu::separator { height: 1px; background: rgba(255,255,255,0.08); margin: 5px 8px; }
QMenuBar { background: transparent; }
QMenuBar::item { padding: 5px 11px; border-radius: 6px; }
QMenuBar::item:selected { background: rgba(168,85,247,0.20); }

/* ---- Status & news bars ---- */
QStatusBar { border-top: 1px solid rgba(255,255,255,0.06); padding: 3px 10px; }
QStatusBar QLabel { padding: 0 8px; }
QStatusBar::item { border: none; }
QToolBar#newsToolBar { border: none; }
QToolBar#newsToolBar QToolButton { border: none; background: transparent; color: #C084FC; padding: 4px 8px; }
QToolBar#newsToolBar QToolButton:hover { text-decoration: underline; }

/* ---- Tooltip ---- */
QToolTip { color: #ffffff; background-color: #2a2a2a; border: 1px solid #7E22CE; border-radius: 6px; padding: 5px 8px; }
)qss");
}

QString DarkTheme::tooltip()
{
    return "";
}
