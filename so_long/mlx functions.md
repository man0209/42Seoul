# void  *mlx_init(void)
- 나의 소프트웨어와 OS의 디스플레이를 연결해주는 함수.

# void  *mlx_new_window(void mlx_ptr, int size_x, int size_y. char *title)
- 디스플레이에 새로운 윈도우를 띄우는 함수. 앞서 받아온 포인터와 가로 세로 크기, 그리고 창의 제목을 받아서 띄운다.

# int mlx_loop(void *mlx_ptr)
- 띄운 창에서 키보드와 마우스의 입력을 기다린다. 혹은 창의 일부를 다시 그리는 역할도 한다.

# int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*func)(), void* param)
- 윈도우 식별자, X11 event, x_mask(mac에선 미사용으로 0 입력), 호출할 함수 포인터(눌린 키와 창에서 눌린 좌표등이 전달됨), 함수에 전달할 파라미터를 인자로 받는 함수
- ex) mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
- x_event
  - 02 : Keypress
  - 03 : KeyRelease
  - 04 : ButtonPress
  - 05 : ButtonRelease
  - 17 : DestroyNotify
- Prototype of event Functions
  - 가로 안은 code 
  - ON_KEYDOWN(2) : int (*f)(int keycode, void *param)
  - ON_KEYUP*(3) : int(*f)(int keycode, void *param)
  - ON_DESTROY(17) : int (*f)(void *param) 

# void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)
  - mlx 포인터, 파일 주소, 가로 세로 크기를 가져와서 메모리에 올리고 해당 메모리의 주소를 반환한다.

# int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
  - 이미지를 받아서 띄울 포인터들을 인자로 받고 윈도우 안에서의 좌표를 지정해서 해당 윈도우에 띄워준다.
