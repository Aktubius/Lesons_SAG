"%JAVA_HOME%\bin\javac" -classpath %JBOSS_DIST%\client\jboss-javaee.jar; com\calc\*.java
"%JAVA_HOME%\bin\jar" cf �alculator.jar com\calc\*.class META-INF\*
"%JAVA_HOME%\bin\javac" -classpath %JBOSS_DIST%\client\jboss-javaee.jar;%JBOSS_DIST%\client\jnp-client.jar; CalculatorClient.java