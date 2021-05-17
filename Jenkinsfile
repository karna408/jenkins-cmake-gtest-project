pipeline{
    agent any
 
        /*----------------------Code Coverage Stage-------------------*/
        stage('Code Coverage'){
            steps{
                sh '''
                  cd $WORKSPACE
                  sh coco.sh
                   '''
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
                    sh "sonar-scanner -Dsonar.projectKey=sample-lib -Dsonar.sources=source"
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

     }
     post {
        always {
            cleanWS()
            
        }
    }
  }



