# Add .local/bin to path
export PATH="$HOME/.local/bin:$PATH"

export EDITOR="nvim"
export TERMINAL="st"
export BROWSER="brave"
export ZDOTDIR="$HOME/.config/zsh"

#cli colors
export CLICOLORS=1
# ls colors
export LS_COLORS='rs=0:di=00;34:ln=00;36:mh=00:pi=40;33:so=00;35:do=00;35:bd=40;33;00:cd=40;33;00:or=40;31;00:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=00;32:*.tar=0'


# from here all are program specific
# for disabling telmetry in .NET SDK
export DOTNET_CLI_TELEMETRY_OPTOUT=1


# Set case insensitive bash autocompletion
bind 'set completion-ignore-case on'

# for some wierd andriod-studio bug in dwm
export _JAVA_AWT_WM_NONREPARENTING=1

# for fzf to ignore node_modules and .git dirs
export FZF_DEFAULT_COMMAND='rg --files --follow --no-ignore-vcs --hidden -g "!{node_modules/**,.git/**,Andriod/**,.andriod/**,.mozilla/**}"'
. "$HOME/.cargo/env"
