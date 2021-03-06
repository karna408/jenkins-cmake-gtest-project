pipeline{
    agent any
    stages{
 
        /*----------------------Code Coverage Stage-------------------*/
        stage('Code Coverage'){
            steps{
                warnError('Script failed'){
                    
                sh '''
                  cd $WORKSPACE
                  sh coco.sh
                   '''
                    
                }

            }
             post {
                always {
                    cobertura coberturaReportFile: 'cocov/cobertura.xml'
                }
            }
        }
       
        /*---------------------------Sonarqube SCA Stage-----------------*/
        stage('Static Code Analysis'){
            steps{
                withSonarQubeEnv('Sonar'){
                    sh "sonar-scanner -Dsonar.projectKey=Jenkins_CMake_Gtest1 -Dsonar.sources=source,test,include"
                }
            }
        }
        /*--------------------------- Build Stage ----------------------- */
        stage('Build'){
            steps{
                sh '''
                  cd $WORKSPACE
                  sh build.sh
                  '''
             }
            post {
               always {
                   archiveArtifacts artifacts: 'install/lib/libapp-sample-addition_lib.a', fingerprint: true
               }
            }
        }
        /*    ----------------- Test Stage ------------------- */
        stage('Test'){
            steps{
                 sh '''
                    cd $WORKSPACE
                    sh test.sh
                 '''
              }
            
            post {
                always {
                    junit allowEmptyResults: true, testResults: 'test/build/*.xml' 
                }
            }
       }
        stage('final-step'){
            steps{
                 sh '''
                    ls
                 '''
            }
        }
    }
    post {
        always {
             emailext (
                 body: '${JELLY_SCRIPT,template="html"}',
                 subject: '$PROJECT_NAME - Build # $BUILD_NUMBER - $BUILD_STATUS!',
                 mimeType: 'text/html',
                 to: 'asapparsha@gmail.com', 
                 attachLog: true
             )
            cleanWs()
        }
    }
}


