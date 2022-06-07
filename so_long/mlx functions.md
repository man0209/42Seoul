# X11 = X Window System, Xorg, X
- X-Window 는 흔히 X11이라고 부르기도 한다. X-Window 는 Unix 계열의 운영체제에서 사용하는 Window 시스템 및 Window에 대한 GUI 환경이다.
- X-Window 는 디스플레이 장치에 Window를 표시하며, 마우스 및 키보드와 같은 입력 장치와 상호작용을 하는 등 GUI 환경 구현을 위한 기본 프레임워크를 제공한다.
- X-Window는 Microsoft의 Windows에서의 GUI시스템과는 달리 네트워크 프로토콜에 기반한 GUI 시스템이다.
- Client-Server Model을 기반으로 하기 때문에 Client 와 Server 간의 네트워크 연결이 요구된다. 
- 서로 네트워크 연결이 되었다면, Client에게 요청을 받았을 때 Server에서 요청을 처리하는 식으로 GUI를 조작하기 때문에 디스플레이 장치에 독립적인 성격을 갖는다.
- 이는 곧 인터페이스의 모습에 관여하지 않는 것을 의미하므로 X-Window를 사용하는 사용자들의 환경이 매우 다양할 수 있다는 것을 암시한다.
- 위으 Client-Server Model에 대해서 간단한 상황을 들어보면, 마우스 포인터를 여기로 움직여라 라고 Client가 요청을 보내면 X-Window의 Server가 요청을 받아 이를 처리하여 디스플레이 장치에 출력해주는 식이 되겠다. 여기서의 Server는 일반적으로 Client의 머신에서 동작하게 되며, 머신의 System Boot File에 의해서 구동된다.
# MiniLibX 
- 42 학생들을 위한 window interface library(그래픽 라이브러리)이다. 작성한 코드를 토대로 window를 표현하기 위해 MiniLibX 라이브러리의 함수를 적재적소에 잘 사용해야 한다.
- mms : MiniLibX 라이브러리의 가장 최신 버전이다. 모니터의 최대 해상도를 받아오는 함수인 mlx_get_screen_size를 사용하려면 mms 라이브러리를 컴파일 해야한다.
- opengl : MiniLibX 라이브러리 구 버전이다.
# void  *mlx_init(void)
- 나의 소프트웨어와 OS의 디스플레이를 연결해주는 함수.
- 연결 성공 : 연결 식별자인 non-null 포인터
- 연결 실패 : NULL

# void  *mlx_new_window(void mlx_ptr, int size_x, int size_y. char *title)
- 디스플레이에 새로운 윈도우를 띄우는 함수. 앞서 받아온 포인터와 가로 세로 크기, 그리고 창의 제목을 받아서 띄운다.
- 반환값 : 이것 또한 다른 함수에서 사용할 수 있는 연결 확인용의 non-null 포인터를 반환.
- 생성 성공 : void *win_ptr : 창 사용 식별자인 non-null pointer
- 생성 실패 : NULL

# int mlx_loop(void *mlx_ptr)
- 띄운 창에서 키보드와 마우스의 입력을 기다린다. 혹은 창의 일부를 다시 그리는 역할도 한다.

# int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*func)(), void* param)
- 윈도우 식별자, X11 event, x_mask(mac에선 미사용으로 0 입력), 호출할 함수 포인터(눌린 키와 창에서 눌린 좌표등이 전달됨), 함수에 전달할 파라미터를 인자로 받는 함수
- X11은 간단히 말해서 MiniLibX 라이브러리 사용자가 쉽게 정의할 수 있는 event 들을 활용하는 라이브러리이다.
- x_event : X11라이브러리에서 정의된 event이다. 발생시키고 싶은 이벤트를 mlx_hook 함수의 매개변수로서 int형으로 입력하면 된다.
- mlx_key_hook과의 차이 : mlx_key_hook는 key를 누를때마다 이벤트가 일시적으로 발생하지만, mlx_hook은 누르고 있는 상태에서 이벤트가 무한히 반복.
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
  - width 와 height은 이미지를 불러오게 되면서 얻게되는 정보. 즉 이미지의 크기가 다르거나, 크기를 통해 전체 해상도를 구하는 등에서 사용이 가능.

# int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
  - 이미지를 받아서 띄울 포인터들을 인자로 받고 윈도우 안에서의 좌표를 지정해서 해당 윈도우에 띄워준다.
  - img_ptr : 사용할 이미지
  - x, y : 이미지가 위치할 창 내의 x, y 좌표
