syntax on
set number
set relativenumber
set autoindent
" set tabs to have 4 spaces
set ts=4

" indent when moving to the next line while writing code
set autoindent

" expand tabs into spaces

" when using the >> or << commands, shift lines by 4 spaces
set shiftwidth=4

" show the matching part of the pair for [] {} and ()
set showmatch

" Plugins will be downloaded under the specified directory.
call plug#begin(has('nvim') ? stdpath('data') . '/plugged' : '~/.vim/plugged')

" Declare the list of plugins.
Plug 'tpope/vim-sensible'
Plug 'junegunn/seoul256.vim'

Plug 'gruvbox-community/gruvbox'
Plug 'sheerun/vim-polyglot'
" List ends here. Plugins become visible to Vim after this call.
Plug 'preservim/nerdtree'

call plug#end()

colorscheme gruvbox
packadd termdebug
let g:termdebug_wide=1
