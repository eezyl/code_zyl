
" ========= Basic Settings ==========
set t_Co=256
set mouse=a
set ruler
set incsearch
set showcmd
set showmatch
set showmode
set ic
set nu
set ai
set cursorline
set scrolloff=3
set wrap
set ignorecase
set smartcase
set wildmenu

set tabstop=4           
set shiftwidth=4        
set expandtab           
set softtabstop=4       
"set relativenumber      

set paste " to avoid being messy when paste 

set backspace=indent,eol,start
colorscheme torte
filetype on
filetype plugin indent on
syntax on      

" inoremap ( ()<Esc>i
" inoremap " ""<Esc>i
" inoremap ' ''<Esc>i
" inoremap [ []<Esc>i
" inoremap { {}<Esc>i
" inoremap { {<CR>}<Esc>ko
" inoremap {{ {}<ESC>i

set hlsearch
" mapping
nnoremap <CR> :nohlsearch<CR><CR>


" ========== advanced settings ==========

" use F4 to vsplit source and header file
map <F4> :call CurtineIncVsp()<CR>
" use F5 to switch source and header file
map <F5> :call CurtineIncSw()<CR>

" use "f" to show current function
fun! ShowFuncName()
  let lnum = line(".")
  let col = col(".")
  echohl ModeMsg
  echo getline(search("^[^ \t#/]\\{2}.*[^:]\s*$", 'bW'))
  echohl None
  call search("\\%" . lnum . "l" . "\\%" . col . "c")
endfun
map f :call ShowFuncName() <CR>

set tags=./tags,./TAGS,tags;~,TAGS;~

" ======= cscope settings begin =======
" set nocscopeverbose
" so ~/config/cscope/cscope_maps.vim

" function! Create_cscope_file(execfile)
"     exe "! bash" a:execfile a:execfile
" endfunction
"
" function! Create_cscope_out(cscope_files)
"     exe "! cscope -bRqk -i" a:cscope_files
" endfunction
"
" if has("cscope")
"     let cscope_exec=findfile("cscope.sh", ".;")
"     if !empty(cscope_exec)
"         if cscope_exec ==? "cscope.sh"
"             set csre
"         endif
"         silent call Create_cscope_file(cscope_exec)
"         let cscope_files=findfile("cscope.files", ".;")
"         if !empty(cscope_files) && filereadable(cscope_files)
"             silent call Create_cscope_out(cscope_files)
"             let cscope_out=findfile("cscope.out", ".;")
"             if !empty(cscope_out) && filereadable(cscope_out)
"                 silent exe "cs add" cscope_out
"             endif
"         endif
"     endif
" endif
" ======= cscope settings end =======

" ======= statusline begin =======
set laststatus=2
"set statusline="%f%m%r%h%w [%Y] [0x%02.2B]%< %F%=%4v,%4l %3p%% of %L"
set statusline=%f       "the filename
set statusline+=%=      "left/right separator
set statusline+=[%{strlen(&fenc)?&fenc:'none'}, "file encoding
set statusline+=%{&ff}] "file format
set statusline+=%h      "help file flag
set statusline+=%m      "modified flag
set statusline+=%r      "read only flag
set statusline+=%y      "filetype
set statusline+=%5c,     "cursor column
set statusline+=%l/%L   "cursor line/total lines
set statusline+=\ %P    "percent through file
" ======= statusline end =======


" taglist settings
nmap <F8> :TlistToggle<CR><CR>
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
set ut=100

nmap <F9> :NERDTree<CR><CR>

" Specify a directory for plugins
" - For Neovim: stdpath('data') . '/plugged'
" - Avoid using standard Vim directory names like 'plugin'
call plug#begin('~/.vim/plugged')
" Make sure you use single quotes

" plugin for quick comment 
  Plug 'preservim/nerdcommenter'
  " Add spaces after comment delimiters by default
  let g:NERDSpaceDelims = 1
  " Use compact syntax for prettified multi-line comments
  let g:NERDCompactSexyComs = 1
  " Align line-wise comment delimiters flush left instead of following code indentation
  let g:NERDDefaultAlign = 'left'
  " Allow commenting and inverting empty lines (useful when commenting a region)
  let g:NERDCommentEmptyLines = 1
  " Enable trimming of trailing whitespace when uncommenting
  let g:NERDTrimTrailingWhitespace = 1
  " Enable NERDCommenterToggle to check all selected lines is commented or not
  let g:NERDToggleCheckAllLines = 1
  map <C-a> <plug>NERDCommenterToggle

  " Install NERDTree
  Plug 'preservim/nerdtree'
  " fzf finder
  " Plug 'junegunn/fzf'

call plug#end()
