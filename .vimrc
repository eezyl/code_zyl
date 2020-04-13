set encoding=utf8        " UTF 8
set fileencodings=utf8
syntax enable            " 語法上色

set nu                   " 顯示行號
set ai                   " 設定自動縮排
set cursorline           " 突出顯示當前行(水平)
" set cursorcolumn         " 突出顯示當前列(垂直)
set scrolloff=3          " 捲動時保留底下三行
set wrap

set tabstop=4            " 設定Tab長度
set shiftwidth=4         " 設定縮排長度為4
set expandtab            " 使用空白取代Tab
set softtabstop=4        " 使得案退格鍵時可以一次刪掉4個空白
" set relativenumber       " 顯示相對行號

set ruler                " 設定尺規 右下方會出現資訊
set incsearch            " 搜索時在未完全輸入完畢要檢索的文本時就開始檢索，可以使用 ctrl+n 來達成自動補完的功
set showmatch            " 顯示括號配對情況
set ic                   " 搜尋不區分大小寫

inoremap ( ()<Esc>i
inoremap " ""<Esc>i
inoremap ' ''<Esc>i
inoremap [ []<Esc>i
inoremap { {}<Esc>i

" inoremap { {<CR>}<Esc>ko
" inoremap {{ {}<ESC>i

filetype indent on        " 啟用依照檔案類型，決定自動縮排樣式的功能
