

struct tuple{
    int pid;
    int duration;
};

typedef struct proc_info {
  int pid;
  int executed_time;
  int on_io;
} proc_info_t;

int sjf_scheduler(proc_info_t *procs_info, int procs_count, int curr_time,
                     int curr_pid)
{
  //Tamaño del array
  int size = array_size(procs_info);
  struct tuple shortest = {-1, __INT_MAX__};
  
  //Recorre el array para determinar el proceso más corto
  for (int i = 0; i < size; i++)
  {
    int cpid = procs_info[i].pid;
    int duration = process_total_time(cpid);
    if (duration < shortest.duration)
    {
      shortest.duration = duration;
      shortest.pid = cpid;
    }
  }
  printf("DUR: %d, PID: %d\n", shortest.duration, shortest.pid);
}

int array_size(proc_info_t *array)
{
  return sizeof(array) / sizeof(array[0]);
}

int main(void)
{
    proc_info_t *proc_info[3];
    proc_info_t proc_info1;

    proc_info1.pid = 1234;
    proc_info1.executed_time = 2323;
    proc_info1.on_io = 1;


}