import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static Map<Integer, List<Integer>> graph = new HashMap();
    public static Map<Integer, Boolean> visited = new HashMap();
    public static Map<Integer, Integer> parent = new HashMap();
    public static Map<Integer, Integer> visitedTime = new HashMap();
    public static Map<Integer, Integer> lowTime = new HashMap();

    public static int time = 0;
    public static int articulationPoints = 0;

    public static void DFS(int root)
    {
        int rootChildren = 0;
        boolean isArticulationPoint = false;
        visited.put(root, true);
        visitedTime.put(root, time);
        lowTime.put(root, time);
        time++;
        for(Integer adj : graph.get(root))
        {
            if(parent.get(root) != adj)
            {
                if(visited.get(adj) == null)
                {
                    parent.put(adj, root);
                    rootChildren++;
                    DFS(adj);
                    if(visitedTime.get(root) <= lowTime.get(adj))
                        isArticulationPoint = true;
                    else
                        lowTime.put(root, Math.min(lowTime.get(root), lowTime.get(adj)));
                }
                else
                {
                    lowTime.put(root, Math.min(lowTime.get(root), visitedTime.get(adj)));
                }
            }
        }
        if((parent.get(root) == null && rootChildren >= 2) ||
            (parent.get(root) != null && isArticulationPoint))
            articulationPoints++;
        return;
    }

    public static void main(String args[] ) throws Exception 
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while(!(line = br.readLine()).equals("0"))
        {
            int n = Integer.parseInt(line);
            int tmp = -1;
            while(!(line = br.readLine()).equals("0"))
            {
                String [] numbers = line.split(" ");
                tmp = Integer.parseInt(numbers[0]);
                for(int i = 1; i < numbers.length; i++)
                {
                    int conn = Integer.parseInt(numbers[i]);
                    if(graph.get(tmp) == null)
                        graph.put(tmp, new ArrayList());
                    graph.get(tmp).add(conn);
                    if(graph.get(conn) == null)
                        graph.put(conn, new ArrayList());
                    graph.get(conn).add(tmp);
                }
            }
            DFS(tmp);
            System.out.println(articulationPoints);
            graph.clear();
            visited.clear();
            parent.clear();
            visitedTime.clear();
            lowTime.clear();
            time = 0;
            articulationPoints = 0;
        }
    }
}
