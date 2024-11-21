
# 🌿 My Dotfiles for Minimal Debian Setup  
A lightweight Debian setup featuring **dwm**, **st**, **dmenu**, and **slock** for a minimalist and efficient workflow.

---

## ✨ Features  
- **Window Manager**: [dwm](https://dwm.suckless.org/) (custom-patched)  
- **Terminal Emulator**: [st](https://st.suckless.org/)  
- **Application Launcher**: [dmenu](https://tools.suckless.org/dmenu/)  
- **Screen Locker**: [slock](https://tools.suckless.org/slock/)  

---

## 🧩 Patches Applied in dwm  
- **Full Gaps**: Add gaps between windows.  
- **Per Tag**: Maintain independent layouts for each tag.  
- **Swallow**: Enable terminal swallowing for better focus.  
- **Rotate Stack**: Easily rotate window order.  
- **Status All Monitors**: Show the status bar on all monitors.  
- **Attach Aside and Below**: Customize new window attachment.  
- **Preserve Tag**: Retain current tag after restarting dwm.  
- **Status2D**: Enable colored and formatted status bars.  
- **Autostart**: Launch scripts or programs automatically.

---

## 🛠️ Build Requirements  
### For dwm  
- `libx11-dev`  
- `libxft-dev`  
- `libxinerama-dev`  
- `libxcb-res0-dev`  
- `libx11-xcb-dev`  

### For slock  
- `libxrandr-dev`  

---

## 📦 Utility Packages  
- **[ly](https://github.com/fairyglade/ly)**: Minimal display manager.  
- **xautolock**: Automatically lock the screen when idle.  
- **clipmenu**: Clipboard history manager integrated with dmenu.  
- **dunst** and **notify-send**: For notifications.  
- **feh**: Set and manage wallpapers.  
- **xdotool**: Control the mouse cursor (useful for dual monitors).  
- **xidlehook**: Modern alternative to xautolock. (cargo install xidlehook)  
- **xclip**: Command-line clipboard utility.  
- **miam**: Lightweight screenshot tool.  
- **pulseaudio**, **pamixer**, **pavucontrol**: For audio management.  
- **[picom](https://github.com/fdev31/picom)**: Compositor for window transparency and shadows (build manually).  

---

## 🚀 Setup Instructions  

1. **Install Debian**  
   Start with a minimal ISO (or any other flavor of Debian).  

2. **Connect to the Internet**  
   Use USB tethering if required.  

3. **Setup `sudo`**  
   - Install `sudo`.  
   - Uncomment the appropriate line in `/etc/sudoers` to grant privileges.  
   - Reboot.  

4. **Install Essential Packages**  
   ```bash
   sudo apt install git neovim linux-headers build-essential xorg NetworkManager mason ninja
   ```

5. **Clone this Repository**  
   ```bash
   git clone <repo-url> ~/dotfiles
   ```
6. **Copy the contents of this repo to respective locations**

7. **Install Utilities**
    ```bash
    sudo apt install ly xautolock clipmenu dunst feh xdotool xidlehook xclip miam pulseaudio pamixer pavucontrol
    ```

8. **Build and Install dwm, st, dmenu, slock**
   - Navigate to respective directories inside ~/.config/suckless and run
   ```bash
   rm -f config.h
   sudo make clean install
   ```

9. **Configure Autostart**
  - Add/remove programs that you want to start before starting dwm in ~/.local/share/dwm/autostart.sh file

10. **Reboot**

Enjoy your minimalist dwm setup.
Happy hacking.
