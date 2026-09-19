class Solution:
    def watchedVideosByFriends(self, watchedVideos: list[list[str]], friends: list[list[int]], id: int, level: int) -> list[str]:
        bfs = set()
        visited = set()
        bfs.add(id)
        visited.add(id)

        for _ in range(level):
            new_bfs = set()
            for p in bfs:
                for friend in friends[p]:
                    if friend not in visited:
                        new_bfs.add(friend)
            visited |= new_bfs
            bfs = new_bfs
        
        vid_count = dict()
        for node in bfs:
            for vid in watchedVideos[node]:
                if vid not in vid_count:
                    vid_count[vid] = 0
                vid_count[vid] += 1
        
        videos = []
        for video, count in vid_count.items():
            videos.append((count, video))
        videos = sorted(videos)
        res = []
        for _, vid in videos:
            res.append(vid)
        return res
