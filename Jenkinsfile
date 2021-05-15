pipeline{
    agent any
 
    /*-------- CODE CLONE ------------ */
    stages{
        stage('git pull'){
            steps{
             sh 'rm -rf $WORKSPACE/*'
            checkout ([$class: 'GitSCM', branches: [[name: '*/master']],
                       userRemoteConfigs: [[url: 'https://github.com/karna408/jenkins-cmake-gtest-project']],
                ])
            }
        }
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
            archiveArtifacts artifacts: 'test/build/app-sample-addition-test', fingerprint: true
            
        }
    }
  }



