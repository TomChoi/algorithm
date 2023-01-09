int solution(vector<string> lines) {
    int answer = 0;


    for (int i = 0; i < lines.size(); i++)
    {
        int end=0;
        int elapsed_time;
        int y, m, d, hh, mm, ss, zzz;
        double elapsed_double;
        sscanf(lines[i].c_str(), "%d-%d-%d %d:%d:%d.%d %lfs", &y, &m, &d, &hh, &mm,&ss, &zzz, &elapsed_double);
        elapsed_time = (int)(elapsed_double * 1000);

        end += hh*60;
        end += mm;
        end *= 60;
        end += ss;
        end *= 1000;
        end += zzz;

        for (int j = end - (elapsed_time-1) -999; j <= end; j++)
        {
            if (j < 0 || j >= BUFF_SIZE)
                continue;
            buff[j] += 1;
            answer = max(answer, buff[j]);
        }
    }

    return answer;
}
