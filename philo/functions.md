# pthread_create
```
int pthread_create (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```
- pthread_create() 는 새로운 스레드를 생성한다.
- 생성되는 새로운 스레드는 arg를 인자로하는 start_routine 함수를 수행한다.
- thread 인자는 NULL이 아니라면, 새로 만든 스레드를 나타내는 스레드 ID를 저장한다.
- attr 인자는 스레드 생성 시 속성을 변경하기 위한 값이며, NULL일 경우 기본 속성을 따른다.
- 성공할 경우 0 리턴, 실패할 경우 0이 아닌 에러 코드를 직접 리턴.
- errno
  - EAGAIN : 새로운 스레드를 만들기 위한 리소스 부족
  - EINVAL : 유효하지 않은 attr 속성 값
  - EPERM : 권한 오류 

# void *start_routine (void *arg);
- start_routine()함수는 상기와 같은 형식을 가진다.
- fork()와 유사하게 새로 생성된 스레드는 부모 스레드로부터 대부분의 속성과 기능, 상태 등을 상속받는다.
- 하지만 프로세스와는 다르게 스레드는 부모 스레드의 리소스를 공유한다.
- 생성된 스레드는 pthread_exit()을 호출하거나 start_routine에서 return 할 경우 종료된다.

# pthread_join
```
int pthread_join(pthread_t thread, void **retval);
```
- pthread_join()은 thread 인자로 명시한 (스레드 ID를 가진) 스레드가 종료될 때까지 대기하도록 한다.
- 해당 스레드가 이미 종료되었다면 pthread_join()은 즉시 리턴된다.
- retval(returnValue)은 NULL이 아닐 경우 종료한 스레드가 리턴한 값이다.
- 정상 종료시 0 리턴, 에러 발생 시 errno 리턴
  - EDEADLK : 데드락 감지
  - EINVAL : thread 는 조인 불가한 스레드
  - ESRCH : thread 인자가 유효하지 않다. 

# pthread_detach
```
int pthread_detach (pthread_t thread);
```
- 기본적으로 스레드는 조인이 가능하도록 생성되지만, pthread_detach()를 이용하면 조인이 가능하지 않도록 하는 것도 가능하다.
- 조인할 생각이 없는 스레드는 detach하면 불필요한 시스템 자원을 낭비하지 않는다.
- thread(스레드 ID)를 인자로 호출에 성공하면 0을 리턴, 실패 시 thread 인자가 유효하지 않다는 의미로 ESRCH 리턴

# 스레드 동기화
- 스레드 생성의 경우 프로세스 생성과 달리 한 프로세스 내에서 생성된 여러 스레드들은 메모리 주소 공간을 공유한다
- 한 프로세스 내에서 생성된 여러 프로세스들이 동시에 특정 전역 변수를 참조하는 경우를 생각해보자
- 예를 들어 예금 계좌 잔액을 나타내는 total 변수가 존재하고, 현재 잔고가 1000원이 있다고 가정할 때, 동시에 두 개의 쓰레드에서 total 변수를 참조해서 100원을 인출하는 상황을 생각해보자
- 첫 번째 스레드에서 현재 잔고가 1000원이므로 100원을 빼서 900원의 값을 total에 할당하는 중이고,
- 두 번째 스레드도 현재 잔고가 1000원인 시점에 참조해서 100원을 빼서 900원의 값을 total에 할당한다면, 실제로는 200원을 빼서 total 변수의 최종 값이 800원이 되어야 하지만 900원인 문제 상황이 발생할 수 있다.
- 위와 같이 동시에 공유 자원에 동시에 접근하는 상태를 `경쟁 상태`라 하고, 동시에 참조되는 공유 자원을 참조하는 영역, 즉 스레드가 실행 중 다른 스레드가 끼어들지 말아야 하는 영역을 `크리티컬 섹션`이라고 한다.
- 이 `크리티컬 섹션`을 `상호 배제(Mutual Exclusion)` 하는 방식으로 접근을 동기화해야 한다.
- pthread에서 상호 배제를 위해 제공하는 락(lock) 매커니즘으로 뮤텍스(mutex)가 존재한다.

# pthread_mutex_loce (뮤텍스 락 걸기)
```
int pthread_mutex_lock (pthread_mutex_t *mutex);
```
- 뮤텍스는 pthread_mutex_t 자료구조로 표현된다.
- 정상수행 시 0리턴, 에러 발생 시 0이 아닌 값 리턴후 errno 설정
- 일반적으로 리턴 값을 검사하지 않는 경향이 있음.
- 
# pthread_mutex_unlock (뮤텍스 락 풀기)
```
int pthread_mutex_unlock (pthread_mutex_t *mutex);
```
- 
