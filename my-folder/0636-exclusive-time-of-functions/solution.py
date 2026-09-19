class Solution:
    def exclusiveTime(self, n: int, logs: list[str]) -> list[int]:
        times = [0] * n
        functions = []
        prev_time = 0
        for log in logs:
            f_id, event, time = log.split(":")
            f_id = int(f_id)
            time = int(time)

            if event == "start":
                if len(functions) > 0:
                    func = functions[-1]
                    times[func] += time - prev_time
                prev_time = time
                functions.append(f_id)
            if event == "end":
                func = functions[-1]
                times[func] += time - prev_time + 1
                prev_time = time + 1
                functions.pop()

        return times
