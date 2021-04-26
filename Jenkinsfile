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
                   mkdir cocov
                   cp include/Addition.h cocov
                   cp source/Addition.cpp cocov
                   cp test/Addition_test.cpp cocov
                   cp test/main.cpp cocov
                   cd cocov
                   g++ -std=c++11 -fprofile-arcs -ftest-coverage -o add Addition.cpp Addition_test.cpp main.cpp -lgtest -lpthread
                   ./add
                   gcovr -r .
                   gcovr -r . --html --html-details -o index.html
                   gcovr -r . --xml-pretty -o cobertura.xml
                   '''
            }
            post {
                always {
                    junit '**/nosetests.xml'
                    step([$class: 'CoberturaPublisher', autoUpdateHealth: false, autoUpdateStability: false, coberturaReportFile: '**/coverage.xml', failUnhealthy: false, failUnstable: false, maxNumberOfBuilds: 0, onlyStable: false, sourceEncoding: 'ASCII', zoomCoverageChart: false])
        }
            }
        }
       
        /*---------------------------Sonarqube SCA Stage-----------------*/
        stage('Static Code Analysis'){
            steps{
                withSonarQubeEnv('Sonar'){
                    sh "sonar-scanner -Dsonar.projectKey=sample-lib -Dsonar.sources=."
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
                    cd $WORKSPACE/test
                    
                    mkdir build
                    cd build
                    cmake .. -DCMAKE_PREFIX_PATH=../install
                    make
                    ./app-sample-addition-test
                 '''
              }
       }

     }
     post {
        always {
            archiveArtifacts artifacts: 'test/build/app-sample-addition-test', fingerprint: true
            
        }
    }
  }



