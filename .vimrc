syntax on

set noerrorbells
set tabstop=4 softtabstop=4
set shiftwidth=4
set expandtab
set smartindent
set rnu
set nowrap
set smartcase
set noswapfile
set nobackup
set undodir=~/.vim/undodir
set undofile
set incsearch
set completeopt-=preview "To remove preview panel of YCM
set clipboard=unnamedplus

":autocmd BufNewFile *.cpp 0r ~/.vim/templates/skeleton.cpp
set cc=120
highlight ColorColumn ctermbg=0 guibg=lightgrey

call plug#begin('~/.vim/plugged')

Plug 'morhetz/gruvbox'
Plug 'jremmen/vim-ripgrep'
Plug 'leafgarland/typescript-vim'
Plug 'vim-utils/vim-man'
Plug 'lyuts/vim-rtags'
Plug 'git@github.com:kien/ctrlp.vim'
Plug 'Valloric/YouCompleteMe' 
Plug 'mbbill/undotree'
Plug 'jiangmiao/auto-pairs' 
Plug 'jalvesaq/Nvim-R', {'branch': 'stable'}

call plug#end()

colorscheme gruvbox
set background=dark

if executable('rg')
    let g:rg_derive_root='true'
endif

""let mapleader = " "
let g:netrw_browse_split=2
let g:netrw_banner = 0
let g:netrw_winsize = 25

let g:ctrlp_use_caching = 0

let g:ycm_autoclose_preview_window_after_completion = 1

nnoremap <F5> :! g++ -o %< %; ./%<<~/Documents/cp/inputf.in <CR>
nnoremap <F1> :0r ~/.vim/templates/skeleton.cpp <CR>12jo
nnoremap <F2> :0r ~/.vim/templates/one_case.cpp <CR>12jo
