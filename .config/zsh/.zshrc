# Enable colors and change prompt:
autoload -U colors && colors

# Load version control information
autoload -Uz vcs_info
precmd() { vcs_info }

# Format the vcs_info_msg_0_ variable
zstyle ':vcs_info:git:*' formats '( %b)'

# Set up the prompt (with git branch name)
setopt PROMPT_SUBST

#PROMPT='[%~]%F{green}${vcs_info_msg_0_}%F{white}$ '
#PS1="%B%{$fg[red]%}[%{$fg[yellow]%}%n%{$fg[green]%}@%{$fg[blue]%}%M %{$fg[magenta]%}%~%{$fg[red]%}]%{$reset_color%}$%b "
PROMPT='%{$fg[red]%}[%{$fg[green]%}%~%{$fg[red]%}]%{$fg[magenta]%}${vcs_info_msg_0_}%{$reset_color%}$%b '

# History in cache directory:
HISTSIZE=1000
SAVEHIST=1000
HISTFILE=~/.cache/zsh/history

# Disable highlighting on paste
zle_highlight=('paste:none')

# Basic auto/tab complete:
autoload -U compinit
zstyle ':completion:*' menu select
# Zsh to use the same colors as ls

zmodload zsh/complist
compinit
_comp_options+=(globdots)		# Include hidden files.

# Basic autocomplete contd.... The case insensitive completion
zstyle ':completion:*' matcher-list 'm:{a-zA-Z}={A-Za-z}'
# case insensitive end

# For rustup completions. Might delete on future
fpath+=~/.zfunc

# vi mode
bindkey -v
export KEYTIMEOUT=1

# Use vim keys in tab complete menu:
bindkey -M menuselect 'h' vi-backward-char
bindkey -M menuselect 'k' vi-up-line-or-history
bindkey -M menuselect 'l' vi-forward-char
bindkey -M menuselect 'j' vi-down-line-or-history
bindkey -v '^?' backward-delete-char

# Change cursor shape for different vi modes.
function zle-keymap-select {
  if [[ ${KEYMAP} == vicmd ]] ||
     [[ $1 = 'block' ]]; then
    echo -ne '\e[1 q'
  elif [[ ${KEYMAP} == main ]] ||
       [[ ${KEYMAP} == viins ]] ||
       [[ ${KEYMAP} = '' ]] ||
       [[ $1 = 'beam' ]]; then
    echo -ne '\e[5 q'
  fi
}
zle -N zle-keymap-select
zle-line-init() {
    zle -K viins # initiate `vi insert` as keymap (can be removed if `bindkey -V` has been set elsewhere)
    echo -ne "\e[5 q"
}
zle -N zle-line-init
echo -ne '\e[5 q' # Use beam shape cursor on startup.
preexec() { echo -ne '\e[5 q' ;} # Use beam shape cursor for each new prompt.

# Use lf to switch directories and bind it to ctrl-o
lfcd () {
    tmp="$(mktemp)"
    lf -last-dir-path="$tmp" "$@"
    if [ -f "$tmp" ]; then
        dir="$(cat "$tmp")"
        rm -f "$tmp"
        [ -d "$dir" ] && [ "$dir" != "$(pwd)" ] && cd "$dir"
    fi
}
bindkey -s '^o' 'lfcd\n'

# Edit line in vim with ctrl-e:
autoload edit-command-line; zle -N edit-command-line
bindkey '^e' edit-command-line

# Load aliases and shortcuts if existent.
[ -f "$HOME/.config/shortcutrc" ] && source "$HOME/.config/shortcutrc"
[ -f "$HOME/.config/zsh/aliasrc" ] && source "$HOME/.config/zsh/aliasrc"

# Fzf settings
FZF_DEFAULT_OPTS="--preview 'batcat --color=always {}'"
FZF_DEFAULT_COMMAND="fd --type f"
#source $HOME/.local/share/fzf/key-bindings.zsh

#for void linux
# Load zsh-syntax-highlighting; should be last.
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh 2>/dev/null
# Load zsh-autosuggestions; should be last.
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh 2>/dev/null

#for debian
#source /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh 2>/dev/null
# Load zsh-autosuggestions; should be last.
#source /usr/share/zsh-autosuggestions/zsh-autosuggestions.zsh 2>/dev/null

. "/home/ghost/.deno/env"
. "/home/ghost/.bun/env"
# bun completions
[ -s "/home/ghost/.bun/_bun" ] && source "/home/ghost/.bun/_bun"

. "/opt/rust/cargo/env"
