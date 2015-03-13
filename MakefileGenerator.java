import java.util.ArrayList;
import java.io.File;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;

public class MakefileGenerator
{
    public static void main(String[] args)
    {
        String outputName;
        if(args.length > 0)
        {
            outputName = args[0];
        }
        else
        {
            outputName = "blackjackGame";
        }

        File src = new File("./src");
        File[] srcFiles = src.listFiles();
	
	// Using the same compile arguments as code::blocks
        final String firstPart = "g++ -Wall -fexceptions -g -I include -c ";

        String makeFile = "";

        makeFile += "all:\n";

        for(File f : srcFiles)
        {
            if(f.getPath().endsWith(".cpp"))
            {
                String path = f.getPath();
                String partialName = path.substring(path.indexOf("/",3),path.indexOf(".",3));
                makeFile += "\t"+ firstPart + f.getPath();
                makeFile += " -o obj"+partialName+".o\n";
            }
        }
        makeFile += "\tg++ -o "+outputName+" obj/*\n";

        makeFile += "clean:\n\trm ./obj/*\n\trm "+outputName+"\n";

        makeFile += "run:\n\tmake all\n\tclear\n\t./"+outputName;

        System.out.println(makeFile);

        BufferedWriter writer;

        try
        {
            writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("Makefile")));
            writer.write(makeFile);
            writer.close();
        }
        catch (Exception ex)
        {
                ex.printStackTrace();
        }
    }

}
