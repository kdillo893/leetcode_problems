import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.LinkOption;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributeView;
import java.nio.file.attribute.BasicFileAttributes;
import java.nio.file.attribute.FileAttributeView;
import java.nio.file.attribute.FileTime;
import java.time.Instant;

/**
 * Fiddling with standard libraries of Java
 */
public class StdLibFiddle {

  public static void main(String[] args) throws IOException {
    // first input string is name of file.
    if (args.length < 1) {
      System.out.println("Usage: day3 [filename]");
      return;
    }
    Path path = Paths.get(args[0]);

    if (path == null) {
      System.err.printf("Bad arg for path: %s\n", args[0]);
      return;
    }

    // have a path, figure out how to parse.
    BufferedReader brReader = Files.newBufferedReader(path);

    // instead of using map or stream things, going to use explicit threads and
    // passing buffer segments of the input file string to parse "mins"

    // I wanna check the file attributes real quick.
    System.out.println("size: " + Files.size(path));
    System.out.println("isDirectory: " + Files.isDirectory(path));
    System.out.println("isRegFile: " + Files.isRegularFile(path));
    System.out.println("isSymLink: " + Files.isSymbolicLink(path));
    System.out.println("isHidden: " + Files.isHidden(path));
    // setting metadata attributes of the file...
    System.out.println("setLastModified: " + Files.setLastModifiedTime(path, FileTime.fromMillis(0)));
    System.out.println("lastModified: " + Files.getLastModifiedTime(path));
    // System.out.println("size: " + Files.setOwner(path, UserPrincipal));
    System.out.println("owner: " + Files.getOwner(path));
    // System.out.println("size: " + Files.setPosixFilePermissions(path,
    // something));
    System.out.println("posixPerms: " + Files.getPosixFilePermissions(path));
    System.out.println("Attributes: ");

    BasicFileAttributeView attrView = Files.getFileAttributeView(path, BasicFileAttributeView.class);
    System.out.println("	creationTime: " + attrView.readAttributes().creationTime());
    System.out.println("	lastAccessTime: " + attrView.readAttributes().lastAccessTime());
    System.out.println("	lastModifiedTime: " + attrView.readAttributes().lastModifiedTime());
    System.out.println("	isOther: " + attrView.readAttributes().isOther());

    // writing an attribute:
    FileTime newTime = FileTime.from(Instant.parse("2001-09-11T14:11:32Z"));
    attrView.setTimes(newTime, newTime, newTime);
    System.out.println("	creationTime: " + attrView.readAttributes().creationTime());
  }
}
