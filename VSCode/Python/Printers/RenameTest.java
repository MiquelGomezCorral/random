import java.io.File;
/**@author decodigo*/
public class RenameTest {
    public static void main(String[] args) {
        String aux = "0052";
        File oldfile = new File("C:/Test/FileGOo11-"+aux+".m4a");
        File newfile = new File("C:/Test/FileGO50-0052.m4a");

        if (oldfile.renameTo(newfile)) {
            System.out.println("archivo renombrado");
        } else {
            System.out.println("error");
        }
        //SOY UN COMENTARIO
    }
}