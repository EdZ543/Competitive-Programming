source $VIMRUNTIME/vimrc_example.vim " default thing from system vimrc

set hls " highlight all search matches
set is " while typing search command, show where the pattern, as it was typed so far, matches
set cb=unnamed " use clipboard as default register
set ts=4 " set tab size
set sw=4 " number of spaces for autoindent
set si " do autoindent when starting new line
set nu " turn on line numbers
set backupdir=/tmp// " remove myfile.txt~ (backup) files from working directory
set directory=/tmp// " remove .swp (unsaved changes) files from working directory
set undodir=/tmp// " remove .un~ (undo file) files from working directory

let g:netrw_sort_by="time" " make file manager sort by time
let g:netrw_sort_direction="reverse" " make file manager sort in reverse

" bracket autocomplete
inoremap {<CR> {<CR>}<Esc>O

" when F5 pressed, save, compile, and execute all at once
autocmd filetype cpp nnoremap <F5> :w <bar> term ++shell g++ -std=c++17 "%" -o "/tmp/%:t:r.exe" && "/tmp/%:t:r.exe"<CR>

" default thing from system vimrc
set diffexpr=MyDiff()
function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  //let arg1 = substitute(arg1, '!', '\!', 'g')
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg2 = substitute(arg2, '!', '\!', 'g')
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  let arg3 = substitute(arg3, '!', '\!', 'g')
  if $VIMRUNTIME =~ ' '
    if &sh =~ '\<cmd'
      if empty(&shellxquote)
        let l:shxq_sav = ''
        set shellxquote&
      endif
      let cmd = '"' . $VIMRUNTIME . '\diff"'
    else
      let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
    endif
  else
    let cmd = $VIMRUNTIME . '\diff'
  endif
  let cmd = substitute(cmd, '!', '\!', 'g')
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3
  if exists('l:shxq_sav')
    let &shellxquote=l:shxq_sav
  endif
endfunction
ndfunction
