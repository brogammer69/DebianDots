"config section
syntax on
set number
set noshowmode "the mode below lightline disappears, ie the default is disabled
set nowrap "lines are not wraped if longer than the window
set tabstop=4 "number of spaces for a tab
set shiftwidth=4 "how many spaces for each level of indentation
set autoindent "preserve indentation
set smartindent "smart indentation for language
set incsearch "incremental search
set hlsearch "highlight search patterns
set ignorecase "case insensitive search
filetype plugin indent on "enalbe syntax highlighting
set noswapfile "vim generally makes a swap file of the opened file. So noswapfile
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o "no repetation of comment to new line


"using vim-plugg
call plug#begin("~/.vim/plugged")
  " Plugin Section
  	Plug 'itchyny/lightline.vim'
  	Plug 'ap/vim-css-color'
  	Plug 'morhetz/gruvbox'
  	Plug 'scrooloose/nerdtree'
	Plug 'ryanoasis/vim-devicons'
call plug#end()

"Config Section
colorscheme gruvbox
set background=dark

" config for file manager
let g:NERDTreeShowHidden = 1
let g:NERDTreeMinimalUI = 1
let g:NERDTreeIgnore = []
let g:NERDTreeStatusline = ''
" Automaticaly close nvim if NERDTree is only thing left open
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
" Toggle
nnoremap <silent> <C-b> :NERDTreeToggle<CR>

"config for auto closing parenthesis and quotes
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O
inoremap <expr> ) strpart(getline('.'), col('.')-1, 1) == ")" ? "\<Right>" : ")"
inoremap <expr> } strpart(getline('.'), col('.')-1, 1) == "}" ? "\<Right>" : "}"
inoremap <expr> ] strpart(getline('.'), col('.')-1, 1) == "]" ? "\<Right>" : "]"
inoremap <expr> ' strpart(getline('.'), col('.')-1, 1) == "\'" ? "\<Right>" : "\'\'\<Left>"
inoremap <expr> " strpart(getline('.'), col('.')-1, 1) == "\"" ? "\<Right>" : "\"\"\<Left>"

"config section for lightline
set laststatus=2 "lightline appears
set ttimeoutlen=30
let g:lightline = {
	      \ 'colorscheme': 'wombat',
      \ }

